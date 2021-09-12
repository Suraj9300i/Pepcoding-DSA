#include<bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define mod 1000000007
#define debug(x) cerr<<#x<<" :- ";_print(x);cerr<<endl;
#define debugArray(x,y) cerr<<#x<<" :- ";_print(x,y);cerr<<endl;
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
void fastIO(){
	#ifndef ONLINE_JUDGE 
	freopen("Error.txt","w",stderr);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
}
template<class T> void _print(T x){cerr<<x;}
template<class T> void _print(vector<T> v){cerr<<"[ ";for(T ele:v) cerr<<ele<<" "; cerr<<"]";}
template<class T> void _print(T arr[],int n){cerr<<"[ ";for(int i=0;i<n;i++) cerr<<arr[i]<<" "; cerr<<"]";}

/***************************Jay Shree Ram****************************/
void printBoard(string board[]){
	for(int i=0;i<10;i++){
		cout<<board[i]<<"";
	}
	cout<<endl;
}
bool canPlaceVertically(string board[],string str,int n,int r,int c){
	if(r-1>=0 && board[r-1][c]!='+') return false;
	if(r+n<10 && board[r+n][c]!='+') return false;
	for(int i=0;i<n;i++){
		if(r+i>=10) return false;
		if(board[r+i][c]=='-' || board[r+i][c]==str[i]) continue;
		return false;
	}
	return true;
}

bool canPlaceHorizontally(string board[],string str,int n,int r,int c){
	if(c-1>=0 && board[r][c-1]!='+') return false;
	if(c+n<10 && board[r][c+n]!='+') return false;
	for(int i=0;i<n;i++){
		if(c+i>=10) return false;
		if(board[r][c+i]=='-' || board[r][c+i]==str[i]) continue;
		return false;
	}
	return true;
}

void solver(string board[],string words[],int nn,int cur){
	if(cur==nn){
		printBoard(board);
		return;
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(board[i][j]=='-' or board[i][j]==words[cur][0]){
				int n = words[cur].size();
				if(canPlaceHorizontally(board,words[cur],n,i,j)){
					// place the word horizantally;
					bool isChar[n] = {0};
					for(int k=0;k<n;k++){
						if(board[i][j+k]==words[cur][k]){
							isChar[k] = 1;
						}
						board[i][j+k] = words[cur][k];
					}
					// printBoard(board);
					solver(board,words,nn,cur+1);
					// unplace the word horizantally;
					for(int k=0;k<n;k++){
						if(!isChar[k]){
							board[i][j+k] = '-';
						}
					}
					// printBoard(board);
				}
				if(canPlaceVertically(board,words[cur],n,i,j)){
					// place the word Vertically;
					bool isChar[n] = {0};
					for(int k=0;k<n;k++){
						if(board[i+k][j]==words[cur][k]){
							isChar[k] = 1;
						}
						board[i+k][j] = words[cur][k];
					}
					// printBoard(board);
					solver(board,words,nn,cur+1);
					// unplace the word Vertically;
					for(int k=0;k<n;k++){
						if(!isChar[k]){
							board[i+k][j] = '-';
						}
					}
					// printBoard(board);
				}
			}
		}
	}
}

void solve(){
	string board[10];
	for(int i=0;i<10;i++){
		cin>>board[i];
	}
	int n;
	cin>>n;
	string words[n];
	for(int i=0;i<n;i++){
		cin>>words[i];
	}
	solver(board,words,n,0);
	// cout<<(canPlaceHorizontally(board,"ANKARA",6,7,2))<<endl;
	// cout<<(canPlaceHorizontally(board,"DELHI",5,3,1))<<endl;
	// cout<<(canPlaceVertically(board,"ICELAND",7,3,5))<<endl;
	// cout<<(canPlaceVertically(board,"LONDON",6,0,1))<<endl;
}

int main(){
	fastIO();
	int t = 1;
	// cin>>t;
	for(int i=1;i<=t;i++){
		solve();
	}

return 0;
}