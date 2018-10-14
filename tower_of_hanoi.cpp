#include<iostream>

using namespace std;
int flag=0;
void tower(int n,char s,char a,char d){
    if(n==1){
        flag++;
        cout<<n<<"->"<<d<<"\n";
        return;
    }
    else{
        tower(n-1,s,d,a);
        cout<<n<<"->"<<d<<"\n";
        flag++;
        tower(n-1,a,s,d);
    }
    return;
}

int main(){
    int n;
    cout<<"\nenter the no of disk to be moved:";
    cin>>n;
    tower(n,'s','a','d');
    cout<<"\nno of steps taken:"<<flag;
    return 0;
}
