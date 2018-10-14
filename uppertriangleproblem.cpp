#include<iostream>

using namespace std;

int arr[110];

void func(int row,int col,int ele){
	int pos;
	pos=((row*(row+1))/2)+col;
	arr[pos]=ele;
}

void transpose(){
    for(int i=0;i<110;i++){
        if(arr[i]!=0){
            int temp = arr[i];
            arr[i] = 0;
            arr[110-i] = temp;
        }
    }
}
int main(){
	int row,col,ele;
	char ch='y';
	do{
		cout<<"\nenter your row:";
		cin>>row;
		cout<<"\nenter your col:";
		cin>>col;
		/*if(row>10 || col>10 || row<col){
			cout<<"\nenter again";
			continue;
		}*/
		cout<<"\nenter your ele:";
		cin>>ele;
		func(row,col,ele);
		cout<<"\nelement added";
		cout<<"\nwant to enter more elements (Y/N)?:";
		cin>>ch;
	}while(ch=='Y' || ch=='y');

	int j=0;
	for(int i=0;i<10;i++){
		for(int k=0;k<=i;k++){
			cout<<arr[j]<<" ";
			j+=1;
		}
		cout<<"\n";
	}
	transpose();
	j=0;
	for(int i=0;i<10;i++){
		for(int k=0;k>=i;k++){
			cout<<arr[j]<<" ";
			j+=1;
		}
		cout<<"\n";
	}
	return 0;
}
