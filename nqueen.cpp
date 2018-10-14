#include<iostream>

using namespace std;

const int n = 5;

bool isok(int x,int y,int board[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i+j)==(x+y)){
                if(board[i][j]!=0)
                    return false;
            }
            if((j-i) == (y-x)){
                if(board[i][j]!=0)
                    return false;
            }

            if(board[x][j]!=0)
                return false;
        }
        if(board[i][y]!=0)
            return false;
    }
    //cout<<"\ntrue";
    return true;
}

bool nqueen(int board[n][n],int nq){
    if(nq==0){
        return true;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isok(i,j,board)){
                board[i][j]=1;
                if(nqueen(board,nq-1)== true){
                    //cout<<"\napplied at yay"<<i<<":"<<j;
                    return true;
                }
                else{
                    //cout<<"\nnot applied at "<<i<<";"<<j;
                    board[i][j]=0;
                }
            }
        }
    }
    return false;
}

int main(){
    int board[n][n]={0};
    if(nqueen(board,n)== false)
        cout<<"\nnot possible.";
    else{
        cout<<"\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<board[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
