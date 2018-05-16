#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;
Node *Read()  
{
	int n,x;
	Node *u,*r,*L;
	L = (Node *)malloc(sizeof(Node));
	r = L;
    cin>>n;
    if(n)
	for(int i=0;i<n;i++)
	{
		u = (Node *)malloc(sizeof(Node));
		cin>>x;
		u->Data = x;
		u->Next = NULL;
		r->Next = u;
		r = u;
	}
	return L;
}

/*List Read()  
{  
    int n;  
    scanf("%d",&n);  
    List L=(List)malloc(sizeof(PtrToNode));   ///����һ��ͷ���  
    L->Next = NULL;        ///ͷָ��Ϊ��  
    if(n)    ///��n����0ʱ  
    {  
        List r=L;     ///r��һ���м�����Ľڵ�  
        for(int i=0;i<n;i++)   
        {  
            List p=(List)malloc(sizeof(struct Node));  
            scanf("%d",&(p->Data)); 
			p->Next = NULL;   ///β�巨  
            r->Next = p;  
            r = p;  
        }  
        r->Next = NULL;           
    }  
    return L;  
}  */

void Print( List L ) /* ϸ���ڴ˲������������NULL */
{
	if(L->Next==NULL)
	{
		cout<<"NULL"<<endl;
		return ;
	}
	L = L->Next;
	while(L!=NULL)
	{
		cout<<L->Data<<" ";
		L = L->Next;
	}
	cout<<endl;
} 

List Merge( List L1, List L2 ){
    List r;
    //����ͷ��������ʹ��L1��L2��ͷ�������Ϊ���Ҫ��L1��L2��ΪNULL
    PtrToNode L = ( PtrToNode )malloc( sizeof( struct Node ) );
    List p = L1->Next;
    List q = L2->Next;
    r = L;
    L->Next=NULL;
    while(p != NULL && q != NULL)
	{
        if(p->Data<q->Data)
		{
            r->Next = p;
            p = p->Next;
            r = r->Next;
        }
        else
		{
            r->Next = q;
            q = q->Next;
            r = r->Next;
        }
    }
    if(p)    
	r->Next = p;
    if(q)   
    r->Next = q;
    L1->Next = NULL;
    L2->Next = NULL;
    return L;
} 

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    Print(L1);
    Print(L2);
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

