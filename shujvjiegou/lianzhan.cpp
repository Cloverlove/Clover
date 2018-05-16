#include<iostream>
using namespace std;
typedef struct lsNode
{
	int data;
	struct lsNode *next;
}sNode,*linkedstack;

void initial(linkedstack &top)
{
	top = new sNode();
	top = NULL;
}

void pushstack(linkedstack &top,int x)
{
	linkedstack s;
	s = new sNode();
	s->data = x;
	s->next = top;
	top = s;
}

int popstack(linkedstack &top,int x)
{
	linkedstack u;
	if(top==NULL)
	return 0;
	else
	{
		x = top->data;
		u = top;
		top = top->next;
		delete u;
		return x;
	}
}

int main()
{
	 int x;
	linkedstack top;
	initial(top);
	for(int i=0;i<5;i++)
	  pushstack(top,i+1);
	for(int i=0;i<5;i++)
	  {
	  	int a;
	  	a = popstack(top,x);
	  	cout<<a<<" ";
	  }
	  cout<<endl;
	  return 0;
}
