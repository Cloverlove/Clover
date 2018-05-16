#include<iostream>
using namespace std;
void merge(int a[],int b[],int c[]){
	int i = 0,j = 0,k = 0;
	while(i<5 && j<4){
		if(a[i] >= b[j]){
		  	 c[k] = b[j];
		  	 j++;
		  	 k++;
		  }
		else{
		  	  c[k] = a[i];
		  	  i++;
		  	  k++;
		  }
	}
	if(i<5)
		c[k++] = a[i++];
     if(j<4)
        c[k++] = b[j++];
}
int main(){
	int a[5] = {0,1,3,4,8};
	int b[4] = {2,6,7,9};
	int c[9];
	merge(a,b,c);
	for(int i=0;i<9;i++)
	  cout<<c[i]<<" ";
	cout<<endl;
	return 0;
}
