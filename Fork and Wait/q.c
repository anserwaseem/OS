#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char*arg[])
{
int arr[10],arr2[10],i;
for(i=1;i<=10;++i)
{
	arr[i-1]=atoi(arg[i]);
	arr2[i-1]=atoi(arg[i]);
}

pid_t cpid;

if(fork()==0)
{
	int j,k,l;
	printf("%s\n","Child1 Asc Sorting");
	for(j=0;j<10;j++)
	{
		for(k=0;k<9;k++)
		{
			if(arr[k]>arr[k+1])
			{
				int aux=arr[k];
				arr[k]=arr[k+1];
				arr[k+1]=aux;
			}
		}
	}

	printf("%s","I am Child1: ");
	for(l=0;l<10;l++)
	{
		printf("%d",arr[l]);
		printf("%s"," ");
	}
	exit(0);
}
else 
	cpid=wait(NULL);
printf("%s\n", "\nChild1 finished, I am parent.");


pid_t c2pid;
if(fork()==0)
{
	int j,k,l;
	printf("%s\n","Child2 Dsc Sorting");
	for(j=0;j<10;j++)
	{
		for(k=0;k<9;k++)
		{
			if(arr[k]<arr[k+1])
			{
				int aux=arr[k];
				arr[k]=arr[k+1];
				arr[k+1]=aux;
			}
		}
	}

	printf("%s","I am Child2: ");
	for(l=0;l<10;l++)
	{
		printf("%d",arr2[l]);
		printf("%s"," ");
	}
	exit(0);
}
else 
	c2pid=wait(NULL);
printf("%s\n", "\nChild2 finished, I am parent.");
printf("%s\n", "Parent process terminating.");
	
return 0;
}
