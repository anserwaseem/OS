#include <semaphore.h>
#include <sys/shm.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

struct IndividualAvg
{
	int sum[2];
	int count[2];
};

struct args
{
	char filename[7];
	struct IndividualAvg* buffer;
};

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
	
	sem_t* semaphore[3];
	semaphore[0]= (sem_t*) shmat(id_sem0, NULL, 0);
	semaphore[1]= (sem_t*) shmat(id_sem1, NULL, 0);
	semaphore[2]= (sem_t*) shmat(id_sem2, NULL, 0);
	buff= (struct IndividualAvg*) shmat(id_cs, NULL, 0);
	
	sem_post(semaphore[0]);//start threads in client side
	printf("waiting untill client side gives signal.\n");
	sem_wait(semaphore[1]);//wait untill client side gives signal

	printf("sum from process 1= %d\n", buff->sum[0]);
	printf("count from process 1= %d\n", buff->count[0]);
	
	printf("sum from process 2= %d\n", buff->sum[1]);
	printf("count from process 2= %d\n", buff->count[1]);
	
	int average = ( (buff->sum[0]+buff->sum[1])/(buff->count[0]+buff->count[1]) ); //calculation of AVERAGE
	buff->sum[0]=buff->sum[1] = average;
	printf("average = %d\n", average);


	int s;
	for(s=0;s<3;s++)
	{
		shmdt(semaphore[s]);
	}
	shmdt(buff);
	shmctl(id_sem0, IPC_RMID, NULL);
	shmctl(id_sem1, IPC_RMID, NULL);
	shmctl(id_sem2, IPC_RMID, NULL);
	shmctl(id_cs, IPC_RMID, NULL);
}
