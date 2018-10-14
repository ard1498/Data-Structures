#include<iostream>

using namespace std;


//pushing into the stack function -->
void push(int item,int index,int *top,int *arr,int size){
	if(top[index]<0){
		if(top[index]==-1){
			top[index]=0;
			arr[top[index]]=item;
		}
		else{
		top[index]=-top[index];
		arr[top[index]]=item;
		}
	}	
	else if(index%2==0 && top[index]>=0){
		if(top[index]==top[index+1]-1 || (top[index]==size-1))
			cout<<"\noverflow condition.";
		else{
			top[index]+=1;
			arr[top[index]]=item;
		}
	}
	else if(index%2!=0 && top[index]>0){
		if(top[index]==top[index-1]+1)
			cout<<"\noverflow condition.";
		else{
			top[index]-=1;
			arr[top[index]]=item;
		}
	}
	else
		cout<<"invalid";
	
	cout<<"\narray is :\n";
	for(int j=0;j<size;j++){
			cout<<arr[j]<<"\t";
		}
}	
		
//function for getting tops of specified no. of stacks-->
void  divide(int no_stacks,int size,int *top){
		int k=1;
		
		for(int i=1;i<no_stacks;i++){
			if(i%2!=0){
				top[i]=(k)*(2*(size/no_stacks))-1;
				k++;
			}	
			else
				top[i]=top[i-1]+1;
		}
		cout<<top[0]<<"\t";
		for(int j=1;j<no_stacks;j++){
			top[j]=-(top[j]);
			cout<<top[j]<<"\t";
		}
	}	
	
	
//our main function-->	
int main(){
	int no_stacks ,size,ch,stkno,item;
	label:
		cout<<"\nenter the no of stacks you want:";
		cin>>no_stacks;
		cout<<"\nenter the size of the array you want to fit in:";
		cin>>size;
	if(no_stacks>size || no_stacks<=0 || size<=0){
		cout<<"\ninvalid entry enter again:";
		goto label;
	}
	int arr[size]={0};
	int top[no_stacks]={-1};
	divide(no_stacks,size,top);
	cout<<"\nwhat do with the stacks you entered:"
		<<"\n1.push element to them."
		<<"\n2.pop from them."
		<<"\n3.display the stack."
		<<"\nenter your choice:";
	cin>>ch;
	char ch2;
	//stkno = 1+index_of_top_array
	do{
	cout<<"\nenter the stack on which you want to operate:";
	cin>>stkno;
	
	switch(ch){
		case 1 : 	cout<<"\nenter the item:";
					cin>>item;
					push(item,stkno-1,top,arr,size);
					cout<<"\nitem added.";
					break;
		//case 2 :	pop(stkno-1,arr);
		//			cout<<"\ndeletion succesfull";
		//			break;
		//case 3 :	display(stkno,arr);
		//			break;
		default:	cout<<"invalid entry of choice";
					break;
	}
	cout<<"\nwant to add more:";
	cin>>ch2;
	}while(ch2=='y' || ch2=='Y');
	return 0;
}
	