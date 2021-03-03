#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<semaphore.h>
#include<pthread.h>

sem_t sem2, sem3, sem4;
int count=0;

struct param
{
	int N;
	int id;
};

void *barrier(void * arg)
{
	struct param obj=*(struct param*) arg;
	printf("Thread number %d\n", obj.id);
	
	sem_post(&sem3);//signal to create next thread.
	
	sem_wait(&sem4);//wait untill all "thread number"s are printed.
	
	printf("Barrier crossed by Thread number %d\n", obj.id);
	count++;
	sem_post(&sem4);//print next barrier statement
	
	if(count==obj.N)//true, if all barriers are crossed
		sem_post(&sem2);//allow main thread to continue its execution to print "all threads have completed".
}

int main(int argc, char* argv[])
{
	struct param obj;
	obj.N=atoi(argv[1]);
	printf("N=%d\n",obj.N);
	
	sem_init(&sem2, 0, 0);
	sem_init(&sem3, 0, 0);
	sem_init(&sem4, 0, 0);
	
	int i;
	for(i=0;i<obj.N;i++)
	{
		obj.id=i;
		pthread_t id;
		pthread_create( &id, NULL, &barrier, (void*)&obj );
		sem_wait(&sem3);//wait untill the line "Thread number" gets printed.
	}
	
	sem_post(&sem4);//signal sem4 that all threads are now created so that it can start printing barrier statements.
	sem_wait(&sem2);//wait untill all barrier statements are printed
	
	printf("All threads have completed their execution.");
	
	sem_destroy(&sem2);
	sem_destroy(&sem3);
	sem_destroy(&sem4);
	
	pthread_exit(NULL);
	return 0;
}
