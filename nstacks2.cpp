//error code..............

#include<iostream>

using namespace std;

//basically implementing queues here in the name of stacks..........
//next is front....
//top is rear.....

class nstacks{
	int* arr;
	int* next;
	int* top;
	int stkno,arrsize,free;				//to store the begining index of free list.......
	
	public:
		nstacks(int stkno,int arrsize){
			this->stkno=stkno;
			this->arrsize=arrsize;
		
			arr = new int[arrsize];
			top = new int[stkno];
			next = new int[arrsize];
			
			int i;
			for(i=0;i<stkno;i++)
				top[i]=-1;
			
			free = 0;
			
			for(i=0;i<arrsize-1;i++)
				next[i]=i+1;
			next[arrsize-1]=-1;	
		}
		
		bool isfull(){
			 return (free == -1);
		}

		void push(int skno,int item){
			if(isfull()){
				cout<<"\noverflow.....";
				return ;
			}
			int index;
			index=free;
			free=next[index];
			next[index]=top[skno];
			top[skno]=index;
			arr[index]=item;
			cout<<"\nelement inserted at :"<<index<<"\nin skno:"<<skno<<"\nat position in stack(top[skno]):"<<top[skno];
		}

		bool isempty(int skno){
			return(top[skno]==-1);
		}
		
		int pop(int skno){
			if(isempty(skno)){
				cout<<"\n underflow>>>>......";
				return 0;
			}
			
			int index;
			index=top[skno];
			top[skno]=next[index];
			next[index]=free;
			free=index;
			return arr[index];
		}	
		
		void display(){
			for( int i=0;i<arrsize;i++)
				cout<<arr[i];
		}	
};			
			
int main(){
	int nostk,maxsize,k;
	cout<<"\nenter the no.of stacks:";
	cin>>nostk;
	cout<<"\nenter no of total elements:";
	cin>>maxsize;
	
	nstacks n1(2,4);
	n1.push(1,3);
	n1.push(2,6);
	n1.push(1,7);
	n1.push(2,8);
	n1.push(2,9);
	cout<<"\narray is:\n";
	n1.display();
	cout<<"\nin 1:";
	k=n1.pop(1);
	cout<<"\nk is:"<<k;
	k=n1.pop(1);
	cout<<"\nk is:"<<k;
	k=n1.pop(1);
	cout<<"\nk is:"<<k;
	
	cout<<"\nin 2:";
	k=n1.pop(2);
	cout<<"\nk is:"<<k;
	k=n1.pop(2);
	cout<<"\nk is:"<<k;
	k=n1.pop(2);
	cout<<"\nk is:"<<k;
	
	return 0;
}	