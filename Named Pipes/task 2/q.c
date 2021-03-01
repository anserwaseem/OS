#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int fd[2]; // fd[0] is used for reading and fd[1] for writing
	if(pipe(fd) == -1) // We have to use pipe for inter-process-communication.
	{
		perror("error while pipe creation.\n");
		exit(1);
	}
	//Using fork()
	if (!fork()) // in parent, output of ls command will go to fd[0]
	{
		close(1); // close the normal stdout
		dup(fd[1]); // after this statement, fd[1] (the writing end of the pipe) is the standard output
		close(fd[0]); // close unused reading end
		execlp("ls", "ls", NULL); // executing ls
	}
	else // in child
	{
		close(0); // close the normal stdin
		dup(fd[0]); // after this statement, fd[0] (the reading end of the pipe) is the standard input
		close(fd[1]); // close unused writing end
		execlp("sort", "sort", NULL); // executing sort
	}
	return 0;
}
