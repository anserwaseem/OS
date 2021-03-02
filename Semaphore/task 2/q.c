#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t sem1,sem2,sem3;

void* printA(void* arg)
{
	while(1)
	{
		sem_wait(&sem3);//decrement value of sem3 from 1 to 0 and print a (unbloced in printB function). After running through this critical section, sem2 will be blocked untill someone unblocks it.
		printf("a");
		sem_post(&sem1);//unblock sem1 by increasing its value from 0 to 1
	}
}
void* printB(void* arg)
{
	while(1)
	{
		sem_wait(&sem2);//decrement value of sem2 from 1 to 0 and print b (unbloced in printC function). After running through this critical section, sem2 will be blocked untill someone unblocks it.
		printf("b");
		sem_post(&sem3);//unblock sem3 by increasing its value from 0 to 1
	}
}
void* printC(void* arg)
{
	while(1)
	{
		sem_wait(&sem1);//decrement value of sem1 and print c. After running through this critical section, sem1 will be blocked untill someone unblocks it.
		printf("c");
		sem_post(&sem2);//unblock sem2 by increasing its value from 0 to 1
	}
}

int main()
{
	pthread_t id1, id2, id3;
	
	sem_init(&sem1, 0, 1);//sem1 will run
	sem_init(&sem2, 0, 0);//initially sem2 will be blocked (because its value is 0)
	sem_init(&sem3, 0, 0);//initially sem3 will be blocked (because its value is 0)
	
	pthread_create(&id1, NULL, &printA, NULL);
	pthread_create(&id2, NULL, &printB, NULL);
	pthread_create(&id3, NULL, &printC, NULL);

	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	pthread_join(id3, NULL);

	sem_destroy(&sem1);
	sem_destroy(&sem2);
	sem_destroy(&sem3);
	pthread_exit(NULL); 
	return 0;
}
