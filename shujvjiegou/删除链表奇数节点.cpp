#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist()
{
	struct ListNode *L = (struct ListNode *)malloc(sizeof(struct ListNode));
	int x;
	struct ListNode *r,*u;
	r = L;
	L->next = NULL;
	cin>>x;
	while(x != -1)
	{
		u = (struct ListNode *)malloc(sizeof(struct ListNode));
		u->data = x;
		u->next = NULL;
		r->next = u;
		r = u;
		cin>>x; 
	}
	return L;
}

struct ListNode *getodd( struct ListNode **L )
{
	struct ListNode *p,*r,*s,*p1,*p2;
	p = *L;
	p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	p1->next = NULL;
	p2->next = NULL;
	r = p1;
	s = p2;
	while(p){ 
       if((p->data)%2 != 0){
      	 	r->next = p;
      	 	r = p;
		}
		 else{
		 	s->next = p;
		    s = p;    
		}
		 p = p->next;
	  }
	  r->next = NULL;
	  s->next = NULL;
	  p2 = p2->next;
	  *L = p2->next;
	  return p1->next;
}

void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *L, *Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd); 
    printlist(L);
    return 0;
}

