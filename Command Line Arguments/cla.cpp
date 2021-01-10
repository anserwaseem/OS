#include<iostream>
using namespace std;

int main(int argc, char *arg[])
{
	cout<<"Count of arguments: "<<argc<<endl;

	int arr[10];
	
	//If argc will be 11, then loop will run 10 times (0-9)
	for(int i=0; i<argc-1; i++)
		arr[i]=atoi(arg[i+1]);
	
	cout<<"Before Sorting;\n";
	for(int i=0; i<argc-1; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	
	for(int c=0; c<argc-1; c++)
		for(int i=0; i<argc-1; i++)
		{
			if(arr[i]>arr[i+1]) //swapping
			{
				int aux=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=aux;
			}
		}
	
	cout<<"After Sorting;\n";
	for(int i=0; i<argc-1; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
		
	return 0;
}
