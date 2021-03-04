#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<semaphore.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<string.h>

void* fm;
int count=0;
sem_t sem;

struct arg
{
	char filename[20];
	char substr[50];
	int start;
	int end;
	int id;
};

void* Search(void* param)//function to search a string (given) in file (given)
{
	struct arg obj = *(struct arg*)param;
	char* data = (char*)fm;
	
	printf("%s%d\n", "Thread", obj.id);
	
	int match = strlen(obj.substr);
	int i=obj.start, j=0, hit=0;
	
	for(i; i<=obj.end; i++)
	{
		if(data[i]==obj.substr[j])
		{
			j++;
			hit++;
			if(hit == match-1)
			{
				sem_wait(&sem);
				count++;
				printf("match found.\n");
				sem_post(&sem);
			}
		}
		else
		{
			hit = 0;		
			j = 0;
		}
	}
	
	printf("\n");
	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	sem_init(&sem, 0, 1);
	struct arg obj;
	strcpy(obj.filename, argv[1]);
	
	//copy first word of substring in the object.
	strcpy(obj.substr, argv[2]);
	
	//if there are multiple words of substring, save them in object too
	int i=3;
	for(i; i<argc; i++)
	{
		strcat(obj.substr, " ");
		strcat(obj.substr, argv[i]);
	}
	//open given file with O_RDWR(read/write) access mode and read/write permission
	int fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	
	//Create the memory mapping.
	fm = mmap(NULL, getpagesize(), PROT_WRITE, MAP_SHARED, fd, 0);
	char* data = (char*)fm;
	
	pthread_t t[2];
	
	obj.id=1;
	obj.start=0;
	obj.end=strlen(data)/2;
	pthread_create(&t[0], NULL, &Search, (void*)&obj);
	pthread_join(t[0], NULL);
	
	obj.id=2;
	obj.start=obj.end;
	obj.end=strlen(data);
	pthread_create(&t[1], NULL, &Search, (void*)&obj);
	pthread_join(t[1], NULL);
	
	printf("%s%d\n", "count=", count);
	
	sem_destroy(&sem);
	munmap(data, getpagesize());
	return 0;
}
