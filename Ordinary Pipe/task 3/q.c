#include<sys/wait.h>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[])
{
int pfd1[2], pfd2[2];
pid_t cpid;
char msg[16]={"HI ThereWERTY er"};

if(pipe(pfd1)==-1)
{
	perror("pipe1 error");
	exit(EXIT_FAILURE);
}
if(pipe(pfd2)==-1)
{
	perror("pipe2 error");
	exit(EXIT_FAILURE);
}

cpid=fork();
if(cpid==-1)
{
	perror("fork error");
	exit(EXIT_FAILURE);
}
if(cpid==0)
{
	close(pfd1[1]);
	close(pfd2[0]);
	int i=0;
	printf("%s\n", "pfd1[0]");
	while(read(pfd1[0],msg,strlen(msg))>0){}
	
	for(i;i<strlen(msg);i++)
	{
		if(msg[i]>96 && msg[i]<123)
			msg[i]-=32;
		else if(msg[i]>64 && msg[i]<91)
			msg[i]+=32;
	}
	//printf("%s\n", msg);
	
	close(pfd1[0]);
	
	printf("%s\n", "pfd2[1]");
	write(pfd2[1], msg, strlen(msg));
	close(pfd2[1]);
	
	exit(EXIT_SUCCESS);
}
else
{

	close(pfd1[0]);
	close(pfd2[1]);

	printf("%s\n", "pfd1[1]");
	write(pfd1[1], msg, strlen(msg));
	close(pfd1[1]);
	
	wait(NULL);
	printf("%s\n", "pfd2[0]");
	read(pfd2[0], msg, strlen(msg));
	printf("%s\n", msg);
	close(pfd2[0]);

	exit(EXIT_SUCCESS);
}

}
