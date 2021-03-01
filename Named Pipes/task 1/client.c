// C program to implement one side of FIFO
// This side reads first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd1;
 
    // FIFO file path
    char * myfifo = "/tmp/myfifo";
 
    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0666);
 
    char str1[20], str2[20];
    //int Operatorr=0,op11=0,op22=0,r=0;
    
    while (1)
    {
        // First open in read only and read
        fd1 = open(myfifo,O_RDONLY);
        /*read(fd1, Operatorr, sizeof(Operatorr));
        read(fd1, op11, sizeof(op11));
        read(fd1, op22, sizeof(op22));*/
        read(fd1, str1, 20);
        
        int i=2,op1=0;
        while(1){
        	op1+=str1[i]-'0';
        	i++;
        	if(str1[i]==' ')
        		break;
        	op1*=10;
        }
        i++;
        int op2=0;
        while(1){
        	op2+=str1[i]-'0';
        	i++;
        	if(str1[i+1]=='\0')
        		break;
        	op2*=10;
        }
        printf("op1:%d\n", op1);
        printf("op2:%d\n", op2);
        
        int r=0;
        if(str1[0]=='+')
        	r=op1+op2;
        else if(str1[0]=='-')
        	r=op1-op2;
        else if(str1[0]=='*')
        	r=op1*op2;
        else if(str1[0]=='/')
        	r=op1/op2;
        str2[0]=r;
        
        // Print the read string and close
        printf("Received from server: %s\n", str1);
        close(fd1);
        sprintf(str2,"%d", r);
        printf("check server side for result\n");
        
        // Now open in write mode and write
        fd1 = open(myfifo,O_WRONLY);
        write(fd1, str2, strlen(str2)+1);
        close(fd1);
    }
    return 0;
}
