#include<iostream>
#include<cstring>

using namespace std;

bool isSafe(bool board[][10],int n,int r,int c){
	for(int i=0;i<=c;i++){
		if(board[r][i])
			return false;
	}
	for(int i=0;i<=r;i++){
		if(board[i][c])
			return false;
	}
	for(int i=r,j=c;i>=0 && j>=0;i--,j--){
		if(board[i][j])
			return false;
	}
	for(int i=r,j=c;i>=0 && j<n;i--,j++){
		if(board[i][j])
			return false;
	}
	return true;
}

void solve(bool board[][10],int n,int lb,int cq){
	if(cq==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<(board[i][j]?"q":"-")<<"	";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	for(int i=lb+1;i<n*n;i++){
		int r = i/n;
		int c = i%n;
		if(isSafe(board,n,r,c)){
			board[r][c] = true;
			solve(board,n,i,cq+1);
			board[r][c] = false;
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
	bool board[n][10];
	memset(board,0,sizeof(board));
	solve(board,n,-1,0);
	return 0;
}