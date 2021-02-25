#include<sys/wait.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[])
{
	int shmid = shmget(12346, 1024, 0);//0666|IPC_CREAT|IPC_EXCL
	
	char* ptr=(char*)shmat(shmid, NULL, 0);
	
	FILE *fp;
	fp=fopen(argv[1], "r");
	
	char c;
	int len=1;
	for(c=getc(fp); c!=EOF; c=getc(fp), len++)//get each char from file
		ptr[len]=c;//then store it in shm (i.e., ptr) at position starting from 1
		
	ptr[0]=len-1;
	printf("%s%s\n%s\n", "Read this from file: ", argv[1], ptr);
	
	while(ptr[0]==len-1);//busy wait
	printf("%s\n", "I am child. Writing this data to file.");
	int i=1;
	for (i; i<= len; i++)
	{
		if(ptr[i]!='#')//store only allowed characters in file
		{
			fputc(ptr[i], fp);
			printf("%c", ptr[i]);
		}
	}
	
	fclose(fp);
	shmdt(ptr);//detach shm
	
	return 0;
}
