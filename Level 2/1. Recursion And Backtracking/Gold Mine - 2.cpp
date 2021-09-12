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
template<class T> void _print(vector<T> v){cerr<<"[ ";for(T ele:v) cerr<<ele<<" "; cerr<<"]\n";}
template<class T> void _print(T arr[],int n){cerr<<"[ ";for(int i=0;i<n;i++) cerr<<arr[i]<<" "; cerr<<"]\n";}

/***************************Jay Shree Ram****************************/
int solver(int mine[][20],int n,int m,int r,int c){
	if(r<0 || r>=n || c<0 || c>=m || mine[r][c]==0){
		return 0;
	}
	int total = mine[r][c];
	mine[r][c] = 0;
	total += solver(mine,n,m,r+1,c);
	total += solver(mine,n,m,r-1,c);
	total += solver(mine,n,m,r,c+1);
	total += solver(mine,n,m,r,c-1);
	return total;
}

void solve(){
    // In java there is mistake in n&m of array
	int n,m;
	cin>>n>>m;
	int mine[n][20];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mine[i][j];
		}
	}
	int ans = INT_MIN;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mine[i][j]!=0){
				int golds = solver(mine,n,m,i,j);
				ans = max(ans,golds);
			}
		}
	}
	cout<<ans;
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