#include<iostream>
using namespace std;
void insertSort(int a[])
{
	int temp,j;
	for(int i=1;i<=4;i++)
	{
	    temp = a[i];
	    
		j = i-1;
		while(a[j]>temp)
		{
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = temp;
	}
}
int main()
{
	int a[5] = {2,3,1,5,0};
	insertSort(a);
	for(int i=0;i<5;i++)
	  cout<<a[i]<<" ";
	  cout<<endl;
	return 0;
}
