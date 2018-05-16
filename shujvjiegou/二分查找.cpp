#include<iostream>
using namespace std;
int bin_search(int a[],int b,int n)
{
	int start = 0,end = n,mid;
	if(n == 0)
	return -1;
	while(start <= end)
	{
		mid = (start + end)/2;
		if(a[mid] == b)
		 return mid;
		else if(a[mid]<b)
		 start = mid + 1;
		else
		  end = mid - 1;
	}
	return -1;
}

int diguifa(int a[],int start,int end,int key) 
{
    int mid;
    if(start>end)
      return -1;
    else
    {
    	mid = (start + end)/2;
    	if(key == a[mid])
    	  return mid;
    	else if(key > a[mid])
    	  return diguifa(a,start,mid-1,key);
    	else
    	  return diguifa(a,mid+1,end,key);
	}
}
int main()
{
	int b,c,n,d;
	cout<<"����n:"<<endl; 
	  cin>>n;
	cout<<"����b:"<<endl; 
	  cin>>b;
	int a[n] ;
	cout<<"��������:"<<endl; 
	for(int i=0;i<n;i++)
	  cin>>a[i];
	cout<<"=======�ǵݹ����======"<<endl;
    c = bin_search(a,b,n);
    if(c != -1)
      cout<<"��Ԫ�ص�λ����:"<<c<<endl; 
    else
      cout<<"û�д�Ԫ��"<<endl;
    cout<<"=====�ݹ����======="<<endl;
    d = diguifa(a,0,n,b);
    if(d > 0)
      cout<<"��Ԫ�ص�λ��:"<<d<<endl;
    else
      cout<<"û�д�Ԫ��"<<endl;
    return 0;
}
