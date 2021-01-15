#include<sys/wait.h>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[])
{
	//initialized two different file descriptors for two different pipes in order to do TWO-WAY communication.
	//cpid variable will deal with process ids.
	int pfd1[2], pfd2[2];
	pid_t cpid;

	//If pipe() call fails: exit
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

	//After the pipe has been set up, two or more processes will be created by a parent-child relationship ie., FORK.
	cpid=fork();
	if(cpid==-1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	//Parent's block
	if(cpid==0)
	{
		//Closing unused write-end of pfd1, and read-end of pfd2
		close(pfd1[1]);
		close(pfd2[0]);
		
		//Empty string rollNo to read from child.
		char rollNo[9];
		printf("%s\n", "pfd1[0]");
		while( read(pfd1[0], rollNo, sizeof(rollNo) )>0){}

		printf("%s\n", rollNo);
		close(pfd1[0]);
		
		//Writing the string studentName to child.
		char studentName[12]={"Anser Waseem"};
		printf("%s\n", "pfd2[1]");
		write(pfd2[1], studentName, sizeof(studentName));
		close(pfd2[1]);
		
		exit(EXIT_SUCCESS);
	}
	//Child's block
	else
	{
		//Closing unused write-end of pfd2, and read-end of pfd1
		close(pfd1[0]);
		close(pfd2[1]);

		//Writing teh string rollNumber to parent.
		char rollNumber[9]={"18L-1129"};
		printf("%s\n", "pfd1[1]");
		write(pfd1[1], rollNumber, sizeof(rollNumber));
		close(pfd1[1]);
		
		//Waiting to let child complete its process.
		wait(NULL);
		
		//Empty string Sname to read from parent.
		char Sname[12];
		printf("%s\n", "pfd2[0]");
		read(pfd2[0], Sname, sizeof(Sname));
		printf("%s\n", Sname);
		close(pfd2[0]);

		exit(EXIT_SUCCESS);
	}
}
