#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT )
{
	if(BT)
	{
		cout<<BT->Data<<" ";
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}

void InorderTraversal( BinTree BT ) 
{
	if(BT)
	{
		InorderTraversal(BT->Left);
		cout<<BT->Data<<" ";
		InorderTraversal(BT->Right);
	}
}

BinTree Insert( BinTree BST, ElementType X )
{
	if(!BST){  
        BST = (BinTree)malloc(sizeof(struct TNode));//��ȻΪ������Ҫ����һ��  
        BST->Data = X;  
        BST->Left = NULL;  
        BST->Right = NULL;  
    }  
    else{//һ�����  
        if(X < BST->Data){//����ֵС�ڽڵ㣬Ӧ��������������λ��  
            BST->Left = Insert(BST->Left,X);//�ݹ����������  
        }  
        else if(X > BST->Data){//����ֵ���ڽڵ㣬Ӧ��������������  
            BST->Right = Insert(BST->Right,X);//�ݹ����������  
        }  
        //������˵��X�Ѿ����ڣ�ʲôҲ����  
    }  
    return BST;  
}

Position Find( BinTree BST, ElementType X )
{
	 while(BST){//ֱ��ѭ�����ң���������  
        if(X < BST->Data){  
            BST = BST->Left;//С�ڽڵ㣬��������  
        }  
        else if(X > BST->Data){//���ڽڵ㣬��������  
            BST = BST->Right;  
        }  
        else{//������ҵ�  
            return BST;  
        }  
    }  
    return NULL;  
}

Position FindMin( BinTree BST )
{
	if(!BST){  
        return NULL;  
    }  
    else if(!BST->Left)  
        return BST;  
    else return FindMin(BST->Left);  
}

Position FindMax( BinTree BST )
{
	 if(!BST)return NULL;  
    else if(!BST->Right)return BST;  
    else return FindMax(BST->Right);  
}

BinTree Delete( BinTree BST, ElementType X )
{
	Position temp;  
    if(!BST){  
        printf("Not Found\n");//���������Ϊ�գ�˵��û��  
    }  
    else{//���������ڲ����ص������ҵ�����ô��  
        if(X < BST->Data){  
            BST->Left = Delete(BST->Left,X);//���������ݹ�ɾ��  
        }  
        else if(X > BST->Data){  
            BST->Right = Delete(BST->Right,X);//���������ݹ�ɾ��  
        }  
        else{//��ǰBST����Ҫɾ���Ľڵ�  
              if(BST->Left && BST->Right){//Ҫ��ɾ���Ľڵ��������������ӣ��ʹ�������������С�������ɾ���Ľڵ�  
                temp = FindMin(BST->Right);//����С  
                BST->Data = temp->Data;//���ɾ���Ľڵ�  
                BST->Right = Delete(BST->Right,temp->Data);//ɾ�����������Ǹ��ڵ�  
              }  
              else{//ֻ��һ���ӽڵ�  
                temp = BST;  
                if(!BST->Left){//ֻ���ҽڵ�  
                    BST = BST->Right;//ֱ�Ӹ�ֵ�Ϳ���  
                }  
                else if(!BST->Right){//ֻ����ڵ�  
                    BST = BST->Left;//ֱ�Ӹ�ֵ�Ϳ���  
                }  
                free(temp);//���ɶҲû��ֱ��ɾ���Ϳ��ԣ���Ȼ�������������ֵ��ҲҪɾ��  
              }  
        }  
    }  
    return BST;  
}

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;
    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); 
	PreorderTraversal(BST); 
	printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); 
	InorderTraversal(BST); 
	printf("\n");

    return 0;
}

