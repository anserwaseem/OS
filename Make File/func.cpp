#include<iostream>
using namespace std;

void sort(int arr[], bool order)
{
	for(int c=0; c<10; c++)
		for(int i=0; i<9; i++)
		{
			if((order==0) && (arr[i]<arr[i+1]))//Descending Order
			{
				int aux=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=aux;
			}
			else if((order==1) && (arr[i]>arr[i+1]))//Ascending Order
			{
				int aux=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=aux;
			}
		}
}

void findHeighest(int arr[], int position)
{
	int order=0;//assuming array is in ascending order
	
	if(arr[0]==arr[9])
	{
		order=2;
		cout<<"Array is neither in ascending order nor in descending.\n";
	}
	else if(arr[0]>arr[9])
		order=1;
	
	if(order==0)
		cout<<"number "<<position<<" highest value of array is: "<<arr[10-position]<<endl;
	else if(order==1)
		cout<<"number "<<position<<" highest value of array is: "<<arr[position-1]<<endl;
}

void print(int arr[])
{
	cout<<"Printing array;\n";
	for (int i=0; i<10; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
