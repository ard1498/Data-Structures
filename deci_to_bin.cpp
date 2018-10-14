#include<iostream>

using namespace std;

void push(int item,int* stack,int &top){
	top+=1;
	stack[top]=item;
}

void convert(int n){
	int k,top=-1,j=0;
	int stack[55];
	int *binary;
	while(n!=1){
		k=(n%2);
		n=n/2;
		push(k,stack,top);
		j++;
	}
	push(n,stack,top);
	int i=0;
	cout<<"\n n's binary is:";
	while(top!=-1){
		cout<<(stack[top]);
		top-=1;
		i++;
	}
}

int main(){
	int n;
	cout<<"\nenter your decimal number:";
	cin>>n;
	convert(n);
	return 0;
}