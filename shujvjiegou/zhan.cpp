#include<iostream>
#define maxlen 100
using namespace std;
typedef struct sStack
{
	int data[maxlen];
	int top;
 }seqStack;
 void initial(seqStack &S)
 {
 	S.top = -1;
 }
 bool stackEmpty(seqStack &S)
 {
 	if(S.top == -1)
 	   return true;
 	else
 	   return false;
 }
 bool stacktop(seqStack &S,int &x)
 {
 	if(stackEmpty(S))
 	   return false;
 	else
 	   {
 	   	 x = S.data[S.top];
 	   	 return true;
		}
 }
 bool stackfull(seqStack &S)
 {
 	if(S.top == maxlen-1)
 	   return true;
 	else
 	   return false;
 }
 bool pushstack(seqStack &S,int &x)
 {
 	if(stackfull(S))
 	   return false;
 	else
 	   {
 	   	  S.top++;
 	   	  S.data[S.top] = x;
 	   	  return true;
		}
 }
 int popstack(seqStack &S,int &x)
 {
 	if(stackEmpty(S))
 	   return 0;
 	else
 	   {
 	   	 x = S.data[S.top];
 	   	 S.top--;
 	   	 return x;
		}
 }
 
 int main()
 {
 	seqStack S;
 	initial(S);
 	int j=0,x;
 	for(int i = 1;i <= 5;i++)
 	     pushstack(S,i);
    for(int i = 1;i <= 5;i++)
       {
       	 int a;
         a = popstack(S,x);
       	 cout<<a<<" ";
	   }
	cout<<endl;
	return 0;
 }
