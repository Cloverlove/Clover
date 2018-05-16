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
	int x;
	Linklist u,r;
	L = (Linklist)malloc(sizeof(Linklist));
	r = L;
	cin>>x;
	while(x!=-1)
	{
		u = (Linklist)malloc(sizeof(Linklist));
		u->data= x;
		u->next = NULL;
		r->next = u;
		r = u;
		cin>>x;
	}
}

int listlength(Linklist &L)
{
	int len = 0;
	Linklist p = L->next;
	while(p!=NULL)
	{
    	len++;
    	p = p->next;
    }
	return len;
}

Linklist getElement(Linklist &L,int i)
{
	Linklist p = L->next;
	int j = 1;
	while(j != i && p != NULL)
	{
		j++;
		p = p->next;
	}
	return p;
}

Linklist listlocation(Linklist &L,int x)
{
	Linklist p = L->next;
	while(p != NULL && p->data!=x)
	 p = p->next;
	return p;
}

bool listinsert(Linklist &L,int i,int x)
{
	Linklist p = L;
	Linklist s;
	int j = 0;
	while(j != i-1 && p != NULL)
	  {
	  	p = p->next;
	  	j++;
	  }
	  if(p == NULL)
	    return false;
	  else
	  {
	  	s = (Linklist)malloc(sizeof(Linklist));
	  	s->data = x;
	  	s->next = p->next;
	  	p->next = s;
	  	return true;
	  }
}

bool listdelete(Linklist &L,int i)
{
	Linklist p,u;
	int j=0;
	p = L;
	while(j != i-1 && p!=NULL)
	{
		p = p->next;
		j++;
	}
	if(p == NULL || p->next == NULL)
		return false;
	else
	{
		u = p->next;
		p->next = u->next;
		delete u;
		return true;
	}
}
void print(Linklist &L)
{
	Linklist p;
	p = L->next;
	while(p)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

int main()
{
	Linklist L;
	initial(L);
	create(L);
	cout<<listlength(L)<<endl;
	cout<<getElement(L,3)<<endl;
	cout<<listlocation(L,4)<<endl;
	if(listinsert(L,5,0)==true)
	   cout<<"²åÈë³É¹¦!"<<endl;
	else
	   cout<<"²åÈëÊ§°Ü!"<<endl;
	print(L);
	if(listdelete(L,5)==true)
	   cout<<"É¾³ý³É¹¦!"<<endl;
	else
	    cout<<"É¾³ýÊ§°Ü!"<<endl;
	print(L);
	return 0;
}
