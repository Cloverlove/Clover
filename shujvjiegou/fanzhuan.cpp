#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct slNode
{
	int data;
	struct slNode *next;
}node,*Linklist;

void initial(Linklist &L)
{
	L = (Linklist)malloc(sizeof(Linklist));
	L->next = NULL;
}

void create(Linklist &L)
{
	Linklist u,r;
	r = L;
	int x;
	cin>>x;
	while(x != -1)
	{
		u = (Linklist)malloc(sizeof(Linklist));
		u->data = x;
		u->next = NULL;
		r->next = u;
		r = u;
		cin>>x;
	}
}
  /*µÝ¹é·½·¨*/ 
/*void xuanhzuan(Linklist &L)
{
	if(L!=NULL)
	{
		xuanhzuan(L->next);
		printf("%d ",L->data);
	}
}*/
Linklist reverse(Linklist &L)
{
	Linklist p,q,pr;
	p = L->next;
	q = NULL;
	L->next = NULL;
	while(p)
	{
		pr = p->next;
		p->next = q;
		q = p;
		p = pr;
	}
	L->next = q;
	return L;
}

void print(Linklist &L)
{
	Linklist p = L->next;
	while(p)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

int main()
{
	Linklist L,L1;
	initial(L);
	create(L);
	print(L);
	//L=L->next;
	//xuanhzuan(L);
	L1 = reverse(L);
	print(L1);
	return 0;
 } 
