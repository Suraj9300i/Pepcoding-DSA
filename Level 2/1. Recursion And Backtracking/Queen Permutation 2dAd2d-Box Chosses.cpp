#include<iostream>
#include<cstring>

using namespace std;

void solve(int board[][10],int n,int r,int c,bool used[],int qc){
    if(r==n-1 && c==n){
        if(qc==n){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]==0) cout<<"-	";
                    else cout<<"q"<<board[i][j]<<"	";
                }
                cout<<endl;
            }
            cout<<endl<<endl;
        }
        return;
    }
    if(c==n){
        r += 1;
        c = 0;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i] = true;
            board[r][c] = i;
            solve(board,n,r,c+1,used,qc+1);
            board[r][c] = 0;
            used[i] = false;
        }
    }
    
    solve(board,n,r,c+1,used,qc);
}

int main(){
    int n;
    cin>>n;
    int board[n][10];
    memset(board,0,sizeof(board));
    bool used[n+1] = {0};
    solve(board,n,0,0,used,0);
    
    return 0;
}