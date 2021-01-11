#include "head.h"

int main(int argc, char *arg[])
{
	cout<<"Total number of arguments: "<<argc<<endl;
	
	int arr[10];
	
	//If argc will be 13, then loop will run 10 times (0-9)
	for(int i=0; i<argc-3; i++)
		arr[i]=atoi(arg[i+1]);
	
	sort(arr, 0);
	findHeighest(arr, 3);
	print(arr);
	
	return 0;
}
