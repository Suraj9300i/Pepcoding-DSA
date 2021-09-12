#include<iostream>
#include<cstring>

using namespace std;

void solve(int n,int r,int c,int board[][10],int qc){
    if(r==n-1 && c==n){
        if(qc==n){
            for(int i=0;i<n;i++){
                  for(int j=0;j<n;j++)
                    cout<<(board[i][j]==1 ? "q" : "-");
                cout<<endl;
            }  
            cout<<endl;
        }
        return;
    }
    if(c==n){
        r += 1;
        c = 0;
    }
    board[r][c] = 1;
    solve(n,r,c+1,board,qc+1);
    board[r][c] = 0;
    
    solve(n,r,c+1,board,qc);
}

int main(){
    int n;
    cin>>n;
    int board[n][10];
    memset(board,0,sizeof(board));
    solve(n,0,0,board,0);
    return 0;
}