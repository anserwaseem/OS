#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

struct myArray
{
	int size;
	int *arr;
};

void* Average(void* param)//function to calculate average of given numbers
{
	struct myArray o = *(struct myArray*) param;
	float avg=0;
	int i=0;
	
	for(i;i<o.size;i++)
		avg+=o.arr[i];
	avg/=o.size;
	
	printf("%s%f\n", "Average: ", avg);
	pthread_exit((void*) &avg);
}

void* Maximum(void* param)//function to calculate maximum of given numbers
{
	struct myArray o = *(struct myArray*) param;
	float max=o.arr[0];
	int i=1;
	
	for(i;i<o.size;i++)
		if(max<o.arr[i])
			max=o.arr[i];
	
	printf("%s%f\n", "Maximum: ", max);
	pthread_exit((void*) &max);
}

void* Minimum(void* param)//function to calculate minimum of given numbers
{
	struct myArray o = *(struct myArray*) param;
	float min=o.arr[0];
	int i=1;
	
	for(i;i<o.size;i++)
		if(min>o.arr[i])
			min=o.arr[i];
	
	printf("%s%f\n", "Minimum: ", min);
	pthread_exit((void*) &min);
}

int main(int argc, char* argv[])
{
	struct myArray obj;
	obj.arr=(int*)malloc((argc-1)*sizeof(int));
	int i=1;
	
	for(i;i<argc;i++)
		obj.arr[i-1]=atoi(argv[i]);
	obj.size=i-1;
	
	pthread_t id[3];
	if(pthread_create(&id[0], NULL, &Average, &obj)==-1)
	{
		printf("%s\n", "Thread creation failed.");
		return -1;
	}
	else
	{
		float avg;
		pthread_join(id[0], (void**)&avg);
		//printf("%s%f\n", "Average = ", avg);
	}
	
	if(pthread_create(&id[1], NULL, &Maximum, &obj)==-1)
	{
		printf("%s\n", "Thread creation failed.");
		return -1;
	}
	else
	{
		float max;
		pthread_join(id[1], (void**)&max);
		//printf("%s%f\n", "Maximum = ", max);
	}
	
	if(pthread_create(&id[2], NULL, &Minimum, &obj)==-1)
	{
		printf("%s\n", "Thread creation failed.");
		return -1;
	}
	else
	{
		float min;
		pthread_join(id[2], (void**)&min);
		//printf("%s%f\n", "Minimum = ", min);
	}
	
	
	return 0;
}
