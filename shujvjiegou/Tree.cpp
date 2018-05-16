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

int GetHeight( BinTree BT )
{
	int m,n;
	if(BT == NULL)
	return 0;
	else
	{
		m = GetHeight(BT->Left);
		n = GetHeight(BT->Right);
		if(m>n)
	      return m+1;
		else
		  return n+1;
	}
}

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}

