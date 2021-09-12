#include<iostream>
#include<cstring>

using namespace std;

bool isSafe(int board[][10],int n,int r,int c){
	//row & column
	for(int i=0;i<n;i++){
		if(board[r][i]>0)
			return false;
		if(board[i][c]>0)
			return false;
	}
	for(int i=r,j=c;i>=0 && j>=0;i--,j--){
		if(board[i][j]>0)
			return false;
	}
	for(int i=r,j=c;i<n && j<n;i++,j++){
		if(board[i][j]>0)
			return false;
	}
	for(int i=r,j=c;i>=0 && j<n;i--,j++){
		if(board[i][j]>0)
			return false;
	}
	for(int i=r,j=c;i<n && j>=0;i++,j--){
		if(board[i][j]>0)
			return false;
	}
	return true;
}

void solve(int board[][10],int n,int qc){
	if(qc>n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(board[i][j]>0) cout<<"q"<<board[i][j]<<"	";
				else cout<<"-	";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	for(int i=0;i<n*n;i++){
		int r = i/n;
		int c = i%n;
		if(board[r][c]==0 && isSafe(board,n,r,c)){
			board[r][c] = qc;
			solve(board,n,qc+1);
			board[r][c] = 0;
		}
	}
}

int main(){
// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt","r",stdin);
// 	freopen("output.txt","w",stdout);
// 	#endif

	int n;
	cin>>n;
	int board[n][10];
	memset(board,0,sizeof(board));
	solve(board,n,1);
	return 0;
}