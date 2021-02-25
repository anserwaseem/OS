#include<sys/wait.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[])
{
	pid_t cpid;
	cpid=fork();
	if(cpid==-1)
	{
		perror(" fork ");
		exit(EXIT_SUCCESS);
	}
	
	if(cpid==0)//child
	{
		int shmid = shmget(12345, 1024, 0);//0666|IPC_CREAT|IPC_EXCL
		
		char* ptr=(char*)shmat(shmid, NULL, 0);
		
		FILE *fp;
		fp=fopen(argv[1], "r");//open file in reading mode
		
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
	}
	else//parent
	{
		int shmid = shmget(12345, 1024, 0);
		
		char* ptr=(char*)shmat(shmid, NULL, 0);
		
		ptr[0]=-1;
		printf("%s\n", "Waiting for child to send data.!");
		
		while(ptr[0]==-1);//busy wait
		
		printf("%s\n%s\n", "I am parent. Received this data from shared memory.", ptr);
		
		int i=1;
		for (i; i<= ptr[0]; i++)
		{
			if(ptr[i]>='A' && ptr[i]<='Z')
				ptr[i]+=32;
			else if(ptr[i]>='a' && ptr[i]<='z')
				ptr[i]-=32;
			else
				ptr[i]='#';
		}
		ptr[0]=-1;//signal child to continue its process.
		
		shmdt(ptr);//detach shm
		shmctl(shmid, IPC_RMID, NULL);//delete shm
	}

	return 0;
}
