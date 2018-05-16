#include<iostream>
#include<malloc.h>
using namespace std;
#define maxlen 100
typedef struct queue
{
	int data[maxlen];
	int front;
	int rear;
}seqQueue,*linklist;

void initial(seqQueue *&Q)
{
	Q = (seqQueue *)malloc(sizeof(struct queue));
	Q->front = 0;
	Q->rear = 0;
}

bool empty(seqQueue *&Q)
{
	if(Q->front == Q->rear)
	return true;
	else
	return false;
}

bool full(seqQueue *&Q)
{
	if(Q->front == ((Q->rear+1)%maxlen))
	return true;
	else
	 return false;
}
int queuetop(seqQueue *&Q,int x)
{
	if(empty(Q))
	return 0;
	else
	{
		x = Q->data[(Q->front+1)%maxlen];
	}
	return x;
}

bool enQueue(seqQueue *&Q,int x)
{
	if(full(Q))
	return false;
	else
	{
		Q->rear = (Q->rear+1)%maxlen;
		Q->data[Q->rear] = x;
		return true;
	}
}

int outQueue(seqQueue *&Q,int x)
{
	if(empty(Q))
	return 0;
	else
	{
		Q->front = (Q->front+1)%maxlen;
		x = Q->data[Q->front];
		return x;
	}
}

int main()
{
	seqQueue *Q;
	initial(Q);
	int a,b,d;
	for(int i=0;i<5;i++)
		enQueue(Q,i+1);
    cout<<"取出的队列头元素是:"<<endl;
    a = queuetop(Q,b);
    cout<<a<<endl;
    cout<<"输出的队列为:"<<endl;
    for(int i=0;i<5;i++)
      {
      	int c;
      	c = outQueue(Q,d);
      	cout<<c<<" ";
	  }
	  cout<<endl;
	  return 0;
}
