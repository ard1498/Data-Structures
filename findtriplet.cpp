//use a sorted array......
#include<iostream>

using namespace std;

int findtriplet(int arr[100],int n,int sum){
    int ptr1=0,ptr2=n-1,t;
    while(ptr2>=ptr1){
        for(int i=(ptr1+1);i<ptr2;i++){
            t = arr[ptr1]+arr[ptr2]+arr[i];
            if(t==sum){
                cout<<arr[ptr1]<<"+"<<arr[i]<<"+"<<arr[ptr2]<<"\n";
                return 1;
            }
        }
        if(t>sum)
            ptr2--;
        else
            ptr1++;
    }
    return 0;
}

int main(){
    int arr[100],n,sum;
    cout<<"\nenter the size of your array:";
    cin>>n;
    cout<<"\nenter the sum of the triplet:";
    cin>>sum;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findtriplet(arr,n,sum);
    return 0;
}
