#include<iostream>
using namespace std;
int main()
{
	int a[5],i,j,min,temp;
	for(int i=0;i<5;i++)
	cin>>a[i];
	for(i=0;i<4;i++)
	{
		min = a[i];
		for(j=i+1;j<5;j++)
		  if(a[j]<min)
		    {
		    	temp = a[j];
		    	a[j] = a[i];
		    	a[i] = temp;
			}
		
	}
	for(i=0;i<5;i++)
	 cout<<a[i]<<" ";
	 return 0;
}
