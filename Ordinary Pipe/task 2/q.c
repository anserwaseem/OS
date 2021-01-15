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
int sum=0;
int arr[10];
int g=0;
for(g;g<10;g++)
	arr[g]=atoi(argv[g+1]);

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
	while(read(pfd1[0],arr,sizeof(arr))>0){}
	for(i=0;i<10;++i)
		sum+=arr[i];
	
	for(i=0;i<10;++i)
		printf("%d\t", arr[i]);
	
	close(pfd1[0]);
	
	printf("%s\n", "pfd2[1]");
	write(pfd2[1], &sum, 1);
	close(pfd2[1]);
	
	exit(EXIT_SUCCESS);
}
else
{

	close(pfd1[0]);
	close(pfd2[1]);

	printf("%s\n", "pfd1[1]");
	write(pfd1[1], arr, sizeof(arr));
	close(pfd1[1]);
	
	wait(NULL);
	printf("%s\n", "pfd2[0]");
	read(pfd2[0], &sum, 1);
	printf("%s", "sum = ");
	printf("%d\n", sum);
	close(pfd2[0]);

	exit(EXIT_SUCCESS);
}

}
