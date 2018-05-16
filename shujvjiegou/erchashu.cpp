#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct lBNode{
	char data;
	struct lBNode *lchild,*rchild;
}BiNode,*BiTree;

void createBiTree(BiTree &T)
{
	T = (BiTree)malloc(sizeof(struct lBNode));
	char x;
	cin>>x;
	if(x == '#')
	  T = NULL;
	else
	{
		T = new BiNode;
		T->data = x;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
}

void PreOrder(BiTree &T)
{
	if(T)
	{
	    cout<<T->data<<" ";
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void Inorder(BiTree &T)
{
	if(T)
	{
		Inorder(T->lchild);
		cout<<T->data<<" ";
		Inorder(T->rchild);
	}
}

void Postorder(BiTree &T)
{
	if(T)
	{
		Postorder(T->lchild);
		Postorder(T->rchild);
		cout<<T->data<<" ";
	}
}

int main()
{
	BiTree T;
	createBiTree(T);
	cout<<"�����������ɹ�"<<endl;
	cout<<"�������"<<endl;
	PreOrder(T);
	cout<<endl;
	cout<<"�������"<<endl;
	Inorder(T);
	cout<<endl;
	cout<<"�������"<<endl;
	Postorder(T);
	return 0;
}
