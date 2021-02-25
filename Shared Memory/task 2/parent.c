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
	ptr[0]=-1;
	shmdt(ptr);//detach shm
	shmctl(shmid, IPC_RMID, NULL);//delete shm
	

	return 0;
}
