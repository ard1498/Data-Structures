#include<iostream>
using namespace std;

void display(int arr[],int n){
    cout<<"\n\t\t\t\t\t"<<arr[0];
    int j=0;
    for(int i=1;i<n-1;i+=2){
        cout<<"\n";
        while(j<=i){
            cout<<"\t\t"<<arr[i+j];
            j++;
        }
    }
}

int main(){
    int arr[]={1,2,3,4,5,6,7};
    display(arr,7);
    return 0;
}
