#include<iostream>
/**
ȡ��Ԫ�ص���ʱ�����������һ��Ԫ���ұ���ʱ����С�����֣�Ȼ�����ǰ�棬
Ȼ�����Ԫ�ص���һ����ʼ�ұ���Ԫ�ش�����֣� Ȼ��������棻ֱ��i==j�����ո����м�ʱ��
����ʱ������ֵ���м������ڽ��еݹ���ã�ֱ���������Ϊֹ 
**/ 
using namespace std;
void pation(int a[],int L,int R)
{
	int i = L,j = R,x = a[L];
	while(i != j)
	  {
	  	 while(i<j && a[j]>x)
	  	   j--;
	  	 if(i<j)
	  	   {
	  	   	 a[i] = a[j];
	  	   	 i++;
			 }
		  while(i<j && a[i]<x)
		    i++;
		  if(i<j)
		    {
		    	a[j] = a[i];
		    	j--;
			}
	  }
	  a[i] = x;
	  if(L<i)
	    pation(a,L,i-1);
	  if(R>i)
	    pation(a,i+1,R);
}

int main()
{
	int a[9] = {2,3,1,0,8,0,2,3,9};
    pation(a,0,8);
	for(int i=0;i<9;i++)
	  cout<<a[i]<<" ";
	  cout<<endl;
	  return 0;
}
