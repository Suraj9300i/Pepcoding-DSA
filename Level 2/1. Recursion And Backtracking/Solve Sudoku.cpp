#include<iostream>

using namespace std;

bool isValid(int board[][10],int r,int c,int x){
    for(int i=0;i<9;i++){
        if(board[r][i]==x)
            return false;
        if(board[i][c]==x)
            return false;
    }
    int a = (r/3)*3;
    int b = (c/3)*3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[a+i][b+j]==x)
                return false;
        }
    }
    return true;
}

void solve(int board[][10],int r,int c){
    if(r==8 && c==9){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
                cout<<board[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    if(c==9){
        r += 1;
        c = 0;
    }
    if(r>=9) return;
    if(board[r][c]!=0){
        solve(board,r,c+1);
    }
    else{
        for(int i=1;i<=9;i++){
            if(isValid(board,r,c,i)){
                board[r][c] = i;
                solve(board,r,c+1);
                board[r][c] = 0;
            }
        }
    }
}

int main(){
    int board[10][10];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cin>>board[i][j];
    }
    solve(board,0,0);
}