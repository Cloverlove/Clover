#include<iostream>
using namespace std;
#define maxlen 100
#include<malloc.h>
typedef struct slist
{
	int data[maxlen];
	int front;
	int rear;
}seqQueue;
void initial(seqQueue &Q)
{
	 Q.front = 0;
	 Q.rear = 0;
}
bool empty(seqQueue &Q)
{
	if(Q.front == Q.rear)
	return true;
	else
	return false;
}
bool full(seqQueue &Q)
{
	if(Q.front == (Q.rear+1)%maxlen)
	return true;
	else
	return false;
}
int queuetop(seqQueue &Q,int x)
{
	if(empty(Q))
	return 0;
	else
	x = Q.data[(Q.front+1)%maxlen];
	return x;
}
bool enqueue(seqQueue &Q,int x)
{
	if(full(Q))
	return false;
	else
	{
		Q.rear = (Q.rear+1)%maxlen;
		Q.data[Q.rear] = x;
		return true;
	}
}
int outqueue(seqQueue &Q,int x)
{
	if(empty(Q))
	return false;
	else
	{
		Q.front = (Q.front+1)%maxlen;
		x = Q.data[Q.front];
		return x;
	}
}
int main()
{
	seqQueue Q;
	initial(Q);
	int a,b,c,d;
	for(int i=0;i<5;i++)
	{
		enqueue(Q,i+1);
	}
	cout<<"队列头元素为:"<<endl;
	a = queuetop(Q,b);
	cout<<a<<endl;
	cout<<"输出的队列元素为:"<<endl;
	for(int i=0;i<5;i++)
	{
		int c = outqueue(Q,d);
		cout<<c<<" ";
	}
	cout<<endl;
	return 0;
}
