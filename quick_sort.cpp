//quicksort using stacks and queue..........

#include<iostream>

using namespace std;


//sorting algorithm used>>>..........
int quicksort(int *arr,int beg,int end,int loc){
    
	while(beg<=end){
		if(loc==end){
			if(arr[loc]<arr[beg]){
				int temp = arr[beg];
				arr[beg]=arr[loc];
				arr[loc]=temp;
				loc=beg;
				end-=1;
				//goto label2;
			}
			else
				beg+=1; 
				//goto label1;
		}
    //label2:
		if(loc==beg){
			if(arr[loc]>arr[end]){
				int temp = arr[end];
				arr[end]=arr[loc];
				arr[loc]=temp;
				loc=end;
				beg+=1;
				//goto label1;
			}
			else
				end-=1;
				//goto label2;
		}
	}	 
	return loc;
}


//using stacks...........................
void partition(int arr[],int size){
    int stack1[20],stack2[20],top=-1,beg,end,n;
    if(size>1){
        top+=1;
        stack1[top]=0;
        stack2[top]=size-1;
        while(top!=-1){
            beg=stack1[top];
            end=stack2[top];
            top-=1;
            n=quicksort(arr,beg,end,end);
			if(beg<n-1){
				top+=1;
				stack1[top]=beg;
				stack2[top]=n-1;
			}
            if(n<end-1){
				top++;
				stack1[top]=n+1;
				stack2[top]=end;
			}
			
        }
    }
	else
		return;
}


//using queue partitioning ............
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


void partition1(int arr[],int size){
	int queue[6],front=-1,rear=-1,k=1,n,beg,end,flag=0;
	if(size>1){
		
		k=insert(queue,6,front,rear,0);
		k=insert(queue,6,front,rear,size-1);
		while(front!=rear){
			
			beg=del(queue,6,front,rear);
			end=del(queue,6,front,rear);
			n=quicksort(arr,beg,end,end);
			if(beg<n-1){
				k=insert(queue,6,front,rear,beg);
				k=insert(queue,6,front,rear,n-1);
			}
            if(n<end-1){
				k=insert(queue,6,front,rear,n+1);
				k=insert(queue,6,front,rear,end);
			}
		}
	}
}	
int main(){
    int arr[]={9,7,5,11,12,2,14,3,10,6};
    partition1(arr,10);
    for(int i=0;i<10;i++)
        cout<<arr[i]<<"\t";
    return 0;
}
