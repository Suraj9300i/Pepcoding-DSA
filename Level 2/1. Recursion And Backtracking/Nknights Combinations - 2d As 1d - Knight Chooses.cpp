#include<iostream>
#include<cstring>

using namespace std;

bool isSafe(bool board[][10],int n,int r,int c){
	if(r-2>=0 && c-1>=0 && board[r-2][c-1])
		return false;
	if(r-2>=0 && c+1<n && board[r-2][c+1])
		return false;
	if(r-1>=0 && c-2>=0 && board[r-1][c-2])
		return false;
	if(r-1>=0 && c+2<n && board[r-1][c+2])
		return false;
	return true;
}

void solve(bool board[][10],int n,int lb,int ck){
	if(ck==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<(board[i][j]?"k":"-")<<"	";
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
			solve(board,n,i,ck+1);
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
	int x[] = {-2,-2,-1,1,2,2,1,-1};
	int y[] = {-1,1,2,2,1,-1,-2,-2};
	bool board[n][10];
	memset(board,0,sizeof(board));
	solve(board,n,-1,0);
	return 0;
}