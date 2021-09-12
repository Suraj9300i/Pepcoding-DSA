#include<iostream>
#include<cstring>

using namespace std;

void solve(int board[][10],int n,int q){
    if(q>n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==0) cout<<"-	";
                else cout<<"q"<<board[i][j]<<"	";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==0){
                board[i][j] = q;
                solve(board,n,q+1);
                board[i][j] = 0;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    int board[n][10];
    memset(board,0,sizeof(board));
    solve(board,n,1);
    
    return 0;
}