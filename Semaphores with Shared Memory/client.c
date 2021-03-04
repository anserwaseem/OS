#include <semaphore.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

struct IndividualAvg
{
	int sum[2];
	int count[2];
	bool tno;
};

struct args
{
	char filename[7];
	struct IndividualAvg* buffer;
};

void* avg(void* argh)
{
	struct args argg=*(struct args*)argh;

	FILE* file = fopen (argg.filename, "r");
	int i=0, s=0, c=0;
	
	fscanf (file, "%d", &i);
	while (!feof (file))
	{  
		printf ("%d\n", i);
		s+=i;
		c++;
		fscanf (file, "%d", &i);    
	}
	
	if(argg.buffer->tno==0)
	{
		argg.buffer->sum[0]=s;
		argg.buffer->count[0]=c;
		printf("sum of integers by %s is %d\n", argg.filename, argg.buffer->sum[0]);
	printf("count of integers by %s is %d\n\n", argg.filename, argg.buffer->count[0]);
		argg.buffer->tno=1;
	}
	else
	{
		argg.buffer->sum[1]=s;
		argg.buffer->count[1]=c;
		printf("sum of integers by %s is %d\n", argg.filename, argg.buffer->sum[1]);
	printf("count of integers by %s is %d\n\n", argg.filename, argg.buffer->count[1]);
	}
	fclose (file);
}

int main()
{
	int id_sem0=shmget(988, 1024, 0);
	int id_sem1=shmget(989, 1024, 0);//0666 | IPC_CREAT | IPC_EXCL
	int id_sem2=shmget(990, 1024, 0);
	int id_cs= shmget(991, 1024,  0);

	if (id_sem0==-1 || id_sem1==-1 || id_sem2==-1 || id_cs==-1)
	{
		printf("shmget ERROR!");
		return 1;
	}
	
	struct IndividualAvg* buff;
	buff->sum[0]=buff->sum[1]=buff->count[0]=buff->count[1] = -1;
	buff->tno=0;
	buff= (struct IndividualAvg*) shmat(id_cs, NULL, 0);
	
	sem_t* semaphore[3];
	semaphore[0]= (sem_t*) shmat(id_sem0, NULL, 0);
	semaphore[1]= (sem_t*) shmat(id_sem1, NULL, 0);
	semaphore[2]= (sem_t*) shmat(id_sem2, NULL, 0);
	
	sem_init(semaphore[0], 1, 0); 
	sem_init(semaphore[1], 1, 0);

	printf("waiting untill server side gives signal.\n");
	sem_wait(semaphore[0]);//wait untill server side gives signal

	pthread_t t1,t2;
	struct args arg1, arg2;
	strcpy(arg1.filename,"f1.txt");
	strcpy(arg2.filename,"f2.txt");
	arg1.buffer=buff;
	arg2.buffer=buff;
	
	if((pthread_create(&t1, NULL, avg, (void*)&arg1))==-1)
	{
		printf("Thread1 creation failed.\n");
		return 0;
	}
	pthread_join(t1, NULL);
	if((pthread_create(&t2, NULL, avg, (void*)&arg2))==-1)
	{
		printf("Thread2 creation failed.\n");
		return 0;
	}
	pthread_join(t2, NULL);

	sem_post(semaphore[1]);//start calculating avg on server side 
	
	/*char a;
	scanf("%c", &a);*/
	
	printf("average from process 1= %d\n", buff->sum[0]);
	printf("average from process 2= %d\n", buff->sum[1]);
	
	printf("Ending client now.\n");

	int s;
	for(s=0;s<3;s++)
	{
		sem_destroy(semaphore[s]);
		shmdt(semaphore[s]);
	}
	shmdt(buff);
	shmctl(id_sem0, IPC_RMID, NULL);
	shmctl(id_sem1, IPC_RMID, NULL);
	shmctl(id_sem2, IPC_RMID, NULL);
	shmctl(id_cs, IPC_RMID, NULL);
}
