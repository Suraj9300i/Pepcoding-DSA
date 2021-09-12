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
bool equalSum(vi ans[],int k){
	int sum = 0;
	for(int ele:ans[0]){
		sum += ele;
	}
	for(int i=1;i<k;i++){
		int ts = 0;
		for(int ele:ans[i]){
			ts += ele;
		}
		if(ts!=sum) return false;
	}
	return true;
}

void solver(int arr[],int n,int k,int cur,vi ans[],int cp){
	if(cur==n){
		if(equalSum(ans,k)){
			for(int i=0;i<k;i++){
				cout<<"[";
				for(int j=0;j<ans[i].size();j++){
					if(j<ans[i].size()-1) cout<<ans[i][j]<<", ";
					else cout<<ans[i][j];
				}
				cout<<"] ";
			}
			cout<<endl;
		}
		return;
	}

	for(int i=0;i<cp;i++){
		ans[i].push_back(arr[cur]);
		solver(arr,n,k,cur+1,ans,cp);
		ans[i].pop_back();
	}
	if(cp<k){
		ans[cp].push_back(arr[cur]);
		solver(arr,n,k,cur+1,ans,cp+1);
		ans[cp].pop_back();
	}
}

void solve(){
	int n,k;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>k;
	vi ans[k];
	solver(arr,n,k,0,ans,0);
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