#include<iostream>
/**
希尔排序算法:基于插入排序算法的思想，但一开始每次走一大步，而不是步长为1了，取step大于1，最后在回归步长为1 
**/
using namespace std;
void shellSort(int a[],int n)
{
	int temp,i,j,d;
    for(d=n/2;d>0;d=d/2)
	{
		for(i=d;i<n;i++)
		{
			temp = a[i];
			j = i;
			while(j>=d && temp<a[j-d])
			{
				a[j] = a[j-d];
				j = j-d;
			}
			a[j] = temp;
		}
	
	}
}
int main()
{
	int a[7] = {2,1,3,3,8,0,9};
	int n = sizeof(a)/sizeof(int);
	shellSort(a,n);
	for(int i=0;i<7;i++)
	   cout<<a[i]<<" ";
	   cout<<endl;
	return 0;
}
