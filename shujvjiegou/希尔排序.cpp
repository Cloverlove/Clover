#include<iostream>
/**
ϣ�������㷨:���ڲ��������㷨��˼�룬��һ��ʼÿ����һ�󲽣������ǲ���Ϊ1�ˣ�ȡstep����1������ڻع鲽��Ϊ1 
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
