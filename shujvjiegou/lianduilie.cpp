#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode *next;
}node;
typedef struct queue
{
	node *front;
	node *rear;
}linkQueue;
void initial(linkQueue *&Q)
{
	Q = (linkQueue *)malloc(sizeof(struct queue));
	Q->front = new node;
	Q->rear = Q->front;
	Q->front->next = NULL;
}
bool queueEmpty(linkQueue *&Q)
{
	return (Q->front == Q->rear);
}
int queueTop(linkQueue *&Q,int x)
{
	if(queueEmpty(Q))
	  return 0;
	else
	  x = ((Q->front)->next)->data;
	return x;
}
void enQueue(linkQueue *&Q,int x)
{
	node *p = new node;
	p->data = x;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}
int outQueue(linkQueue *&Q,int x)
{
	node *u;
	if(queueEmpty(Q))
	 return 0;
	else
	{
		x = Q->front->next->data;
		u = Q->front->next;
		Q->front->next = u->next;
		delete u;
		if(Q->front->next == NULL)
		Q->rear = Q->front;
		return x;
	}
}
int main()
{
	linkQueue *Q;
	initial(Q);
	int a,c,d,x;
	for(int i=0;i<5;i++)
	  enQueue(Q,i+1);
	cout<<"队列头元素为:"<<endl;
	a = queueTop(Q,x);
	cout<<a<<endl;
	for(int i=0;i<5;i++)
	{
		int b = outQueue(Q,c);
		cout<<b<<" ";
	}
	cout<<endl;
	return 0;
}
