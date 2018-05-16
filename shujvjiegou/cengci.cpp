#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree()
{
	BinTree T = (BinTree)malloc(sizeof(struct TNode));
	char x;
	cin>>x;
	if(x == '#')
	  T = NULL;
	else
	{
		T->Data = x;
		T->Left = CreatBinTree();
		T->Right = CreatBinTree();
	}
	return T;

}
void InorderTraversal( BinTree BT )
{
	if(BT)
	{
		cout<<BT->Data<<" ";
		InorderTraversal(BT->Left);
	    InorderTraversal(BT->Right);
	}
}
void PreorderTraversal( BinTree BT )
{
	if(BT)
	{
		PreorderTraversal(BT->Left);
		cout<<BT->Data<<" ";
		PreorderTraversal(BT->Right);
	}
}
void PostorderTraversal( BinTree BT )
{
	if(BT)
	{
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		cout<<BT->Data<<" ";
	}
}
void LevelorderTraversal( BinTree BT )
{
	BinTree q[100];
    BinTree p;
    int front = 0,rear = 0;
    if(!BT) 
	 return;
    if(BT){
        q[rear++] = BT; 
        while(rear != front){
        	//取出队头元素，并使头指针向后移动一位 
            p = q[front++];
            printf(" %c",p->Data); 
            if(p->Left)     
			q[rear++] = p->Left;
            if(p->Right)    
			q[rear++] = p->Right;
        } 
    }

}

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");    
	InorderTraversal(BT);    
	printf("\n");
    printf("Preorder:");   
	PreorderTraversal(BT);   
	printf("\n");
    printf("Postorder:");  
	PostorderTraversal(BT);  
	printf("\n");
    printf("Levelorder:"); 
	LevelorderTraversal(BT); 
	printf("\n");
    return 0;
}

