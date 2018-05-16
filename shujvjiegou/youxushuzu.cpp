#include <iostream>
using namespace std;
#include<malloc.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

void initial(List &L)
{   
    int n,x;
	L = (List)malloc(sizeof(struct LNode));
	L->Last = 0;
}
void ReadInput(List &L)/* 裁判实现，细节不表。元素从下标0开始存储 */
{	
	int n,i,x;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		L->Data[i] = x;
		L->Last++;
	}
  
}

void PrintList( List L ) /* 裁判实现，细节不表 */
{
	for(int i=0;i<L->Last;i++)
	cout<<L->Data[i]<<" ";
	cout<<endl;
}

bool Insert(List L,ElementType X )
{
	int i = L->Last-1;
	if(i >= MAXSIZE-1)
	    return false;
	else
	{
		for(int j=0;j<L->Last;j++)
		  if(L->Data[j] == X)
     	    return false;
		while(i>=0&&L->Data[i]>X)
		{
	    	L->Data[i+1] = L->Data[i];
	    	i--;
     	}
     	    L->Data[i+1] = X;
		    L->Last++;
		    return true; 
	}
}

int main()
{
    List L;
    ElementType X;
    initial(L);
    ReadInput(L);
    cin>>X;
    if(Insert(L,X) == false)
    cout<<"eroor"<<endl;
    PrintList(L);
    return 0;
}

