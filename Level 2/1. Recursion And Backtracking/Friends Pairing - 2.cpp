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
int sn = 1;
void solver(int n,int cur,bool used[],string ans){
	if(cur>n){
		cout<<sn<<"."<<ans<<endl;
		sn++;
		return;
	}
	if(used[cur]){
		solver(n,cur+1,used,ans);
	}
	else{
		solver(n,cur+1,used,ans+"("+to_string(cur)+") ");
		for(int i=cur+1;i<=n;i++){
			if(!used[i]){
				used[i] = true;
				solver(n,cur+1,used,ans+"("+to_string(cur)+","+to_string(i)+") ");
				used[i] = false;
			}
		}
	}
}

void solve(){
	int n;
	cin>>n;
	bool used[n+1] = {0};
	solver(n,1,used,"");
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