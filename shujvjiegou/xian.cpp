#include<iostream>
#include<malloc.h> 
using namespace std;
#define maxlen 1000
typedef struct sList
{
	int data[maxlen];
	int listlen;
}seqlist;
void initial(seqlist *&L)
{
	L = (seqlist *)malloc(sizeof(seqlist));
	L->listlen = 0;
}
int insert(seqlist *L,int i,int x)
{
	int j;
	if(L->listlen == maxlen)
	return 0;
	else if(i<1||i>L->listlen+1)
	return 1;
	else
	{
		for(j=L->listlen-1;j>=i-1;j--)
		 L->data[j+1] = L->data[j];
		 L->data[i-1] = x;
		 L->listlen++;
		 return 2; 
	}
}
int find(seqlist *&L,int x)
{   
    int i;
    for(i=0;i<L->listlen;i++)
      if(x==L->data[i])
      return i+1;
      return 0;
}
int location(seqlist *&L,int i)
{
	int x;
	if(i<1||i>L->listlen)
	return 0;
	else
	{
	x = L->data[i-1];
	return x;
}
}
int listdelete(seqlist *&L,int i)
{
	int j;
	if(i<1||i>L->listlen)
	return 0;
	else
	{
		for(j=i;j<L->listlen;j++)
		L->data[j-1] = L->data[j];
		L->listlen--;
		return 1; 
	}
}
int main()
{
	seqlist *L;
	initial(L);
	int x,a,b;
	for(int i=0;i<5;i++)
	{
		cin>>x;
		L->data[L->listlen++] = x;
	}
	insert(L,3,0);
	cout<<L->listlen<<endl;
	a = find(L,3);
	b = location(L,6);
	cout<<"查找的位置:"<<a<<endl;
	cout<<"按照序号求解:"<<b<<endl;
	for(int i=0;i<L->listlen;i++)
	cout<<L->data[i]<<" ";
	cout<<endl;
	listdelete(L,1);
	for(int i=0;i<L->listlen;i++)
	cout<<L->data[i]<<" ";
	return 0;
}
