#include<iostream>
/**
取首元素到临时变量，从最后一个元素找比临时变量小的数字，然后调到前面，
然后从首元素的下一个开始找比首元素大得数字， 然后调到后面；直到i==j，当空格在中间时，
把临时变量赋值给中间数。在进行递归调用，直至完成排序为止 
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
