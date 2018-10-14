#include<iostream>

using namespace std;
int arr[30];

void push(int &top1,int &top2,int item,int stkno){
	if(top2==top1+1)
		cout<<"\noverflow";
	else{
		if(stkno==1){
			top1=top1+1;
			arr[top1]=item;
			cout<<"\nelement added in stack"<<stkno;
		}
		if(stkno==2){
			top2=top2-1;
			arr[top2]=item;
			cout<<"\nitem added in stack"<<stkno;
		}
	}
}

int pop(int &top1,int &top2,int stkno){
	
	if(stkno==1){
		if(top1==-1){
			cout<<"underflow";
			return 0;
		}
		else{
			arr[top1]=0;
			top1=top1-1;
		}
	}
	if(stkno==2){
		if(top2==30){
			cout<<"underflow";
			return 0;
		}
		else{
			arr[top2]=0;
			top2=top2+1;
		}	
	}
	return 1;
}	

int main(){
	int stkno,ch,no;
	int top1=-1,top2=30;
	cout<<"\nenter the no of stacks u want to create:";
	cin>>no;
	cout<<"\nenter want to do with stacks:"
			<<"\n1.add item to stack."
			<<"\n2.pop item from stack."
			<<"\n3.display stack."
			<<"\nenter your choice:";
	cin>>ch;
	//if(ch==1){
					int item;
					char ch1='y';
					do{
						cout<<"\nenter the item you want to add:";
						cin>>item;
						cout<<"\nenter the stack no. to add item:";
						cin>>stkno;
						push(top1,top2,item,stkno);
						cout<<"\nwant to add more elements:";
						cin>>ch1;
					}while(ch1=='Y' || ch1=='y');
	//}
	if(ch==2){
			cout<<"\nenter the stack no. to delete item:";
			cin>>stkno;
			cout<<pop(top1,top2,stkno);
	}		
		
	for(int i=0;i<30;i++){
		cout<<arr[i];
	}
	return 0;
}	