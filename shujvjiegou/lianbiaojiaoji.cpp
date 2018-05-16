#include<iostream>
#include<malloc.h>
#include<stdlib.h>
using namespace std;
typedef struct slNode
{
	int data;
	struct slNode *next;
}node,*Linklist;
Linklist create()
{
	Linklist L;
	L = (Linklist)malloc(sizeof(struct slNode));
	Linklist u,r;
	int x;
	r = L;
	L->next = NULL;
	cin>>x;
	while(x != -1)
	{
		u = (Linklist)malloc(sizeof(struct slNode));
		u->data = x;
		u->next = NULL;
		r->next = u;
		r = u;
		cin>>x; 
	}
	return L;
	
}

Linklist merge(Linklist L1,Linklist L2)
{
	Linklist L3 = (Linklist)malloc(sizeof(struct slNode));
	Linklist p,q,r;
	r = L3;
	L3->next = NULL;
	p = L1->next;
	q = L2->next;
     while(p && q)
     {
     	if(p->data == q->data)
     	  {
     	  	r->next = p;
     	  	r = p;
     	  	p = p->next;
     	  	q = q->next;
		 }
		 else if(p->data > q->data)
		    q = q->next;
		 else
		    p = p->next;	   
	 }

/*
	while(p != NULL)
	{
		
		  while(p->data != q->data && q != NULL)
		{
			q = q->next;
		}
	
	    if(p->data == q->data)
		{
		    r->next = p->next;
		    r = p;
		    r->next = NULL;
			p = p->next;
		}
		else
		   p = p->next;
	}*/
	
	return L3;
}

void printn(Linklist &L)
{
	Linklist p = L->next;
	while(p)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
}
int main()
{
	Linklist L1,L2,L3;
	L1 = create();
	L2 = create();
	L3 = merge(L1,L2);
	printn(L3);
	return 0;
}
