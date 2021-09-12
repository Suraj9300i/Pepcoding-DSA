#include<iostream>
#include<cstring>

using namespace std;

void solve(int board[],int n,int q,int lb){
    if(q==n){
        for(int i=0;i<n*n;i++){
            if(i!=0 && i%n==0) cout<<endl;
            cout<<(board[i]==0 ? "-	" : "q	");
        }
        cout<<endl<<endl;
        return;
    }
    for(int i=lb+1;i<n*n;i++){
        board[i] = 1;
        solve(board,n,q+1,i);
        board[i] = 0;
    }
}

int main(){
    int n;
    cin>>n;
    int board[n*n];
    memset(board,0,sizeof(board));
    solve(board,n,0,-1);
    return 0;
}