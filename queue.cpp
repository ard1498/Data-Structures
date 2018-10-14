//ime

#include<iostream>

using namespace std;

int insert(int queue[],int size,int &front,int &rear,int item){
	if((rear==size-1 && front==0)|| front==rear+1){
		cout<<"\noverflow..";
		return 0;
	}
	else if(front==-1){
		front++;
		rear=front;
	}
	else if(rear==size-1)
		rear=0;
	else
		rear++;
	queue[rear]=item;
	return 1;
}	
		
int del(int queue[],int size,int &front,int &rear){
		int item;
		if(front==-1){
			cout<<"\nunderflow.....";
			return -1;
		}	
		else{
			item=queue[front];
			if(front==rear){
				front=-1;
				rear=-1;
			}
			else if(front==size-1)
				front=0;
			else
				front++;
		}
		return item;
}

//just for demo not working properly.......///////			
void display(int queue[],int size,int front,int rear){
	if(front==-1){
		cout<<"\nqueue is empty......";
		return;
	}
	else{
		cout<<queue[front]<<"<-";
		while(front!=rear){
			if(front==size-1)
				front=0;
			else
				front++;
		}
		cout<<queue[front];
	}
}	



int main(){
	int size;
	cout<<"\nsize of your queue:";
	cin>>size;
	int queue[size]={-1};
	int ch,front=-1,rear=-1;
	do{
		cout<<"\nwant to insert elements(1)."
			<<"\nwant to delete elements(2)."
			<<"\nwant to dispaly elements(3).\n";
		cin>>ch;
		switch(ch){
			case 1 :int item,k; 
					cout<<"\nenter item to be inserted:";
					cin>>item;
					k=insert(queue,size,front,rear,item);
					if(k==0)
						cout<<"\nsorry item not inserted:"<<item;
					else
						cout<<"\nitem inserted:"<<k;
					break;
			case 2 :int ret;
					ret=del(queue,size,front,rear);
					if(ret==-1)
						cout<<"\nsorry...queue ids empty";
					else
						cout<<"\nitem deleted:"<<ret;
					break;
			case 3 :display(queue,size,front,rear);
					break;
			default:cout<<"\nno such command>>...";
					break;
		}
	}while(ch==1 || ch==2||ch==3);
	return 0;
}	
			
