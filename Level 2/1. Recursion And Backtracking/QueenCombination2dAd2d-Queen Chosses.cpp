#include<iostream>
#include<cstring>

using namespace std;

void solve(int board[][10],int n,int q,int lr,int lc){
    if(q==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==0) cout<<"-	";
                else cout<<"q	";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int i=lr;i<n;i++){
        int j;
        if(i==lr) j=lc+1;
        else j=0;
        for(;j<n;j++){
            board[i][j] = 1;
            solve(board,n,q+1,i,j);
            board[i][j] = 0;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int board[n][10];
    memset(board,0,sizeof(board));
    solve(board,n,0,0,-1);
    return 0;
}