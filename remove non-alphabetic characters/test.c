#include<iostream>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main() {

	FILE *f2, *o2;
	f2 = fopen("input.txt", "r");
	if(f2==NULL)
	{
		printf("cannot open file. f2");
	}
	o2 = fopen("output.txt", "w");
	if(o2==NULL)
	{
		printf("cannot open file. o2");
	}
	int c2=getc(f2);
	while (c2!=EOF)
	{
		if( (c2<48) || (c2>57 && c2<65) || (c2>90 && c2<97) || (c2>122) )
		{
			putc(c2,o2);
		}
		c2=getc(f2);
	}
	fclose(f2);
	fclose(o2);
	printf("Check output.txt file for output.\n");

	return 0;
}
