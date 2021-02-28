#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

void* fun(void* param)//function to print fibonacci series
{
	int n = *(int*) param;
	int a=0, b=1;
	
	printf("%d %d ", a, b);
	do
	{
		int aux=b;
		b=a+b;
		a=aux;
		printf("%d ", b);
	}while(b<n);
}

int main(int argc, char* argv[])
{
	int i=1, n[argc];
	for(i;i<argc;i++)
	{
		pthread_t id;
		n[i-1]=atoi(argv[i]);
		printf("\n%s%d%s", "Thread ", i, ": ");
		if(pthread_create(&id, NULL, &fun, &n[i-1])==-1)
		{
			printf("%s\n", "Thread creation failed.");
			return -1;
		}
		pthread_join(id, NULL);
	}

	return 0;
}
