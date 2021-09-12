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

/***************************Jay Shree Ram****************************/
vi fs1,fs2;
int mn_diff = INT_MAX;
void solver(int arr[],int n,int cur,vi s1,vi s2,int x,int y){
	if(cur==n){
		int sum1 = 0,sum2 = 0;
		for(int ele:s1) sum1+=ele;
		for(int ele:s2) sum2+=ele;
		int diff = abs(sum1-sum2);
		if(diff<mn_diff){
			fs1 = s1;
			fs2 = s2;
			mn_diff = diff;
		}
		return;
	}
	if(x>0){
		s1.push_back(arr[cur]);
		solver(arr,n,cur+1,s1,s2,x-1,y);
		s1.pop_back();
	}
	if(y>0){
		s2.push_back(arr[cur]);
		solver(arr,n,cur+1,s1,s2,x,y-1);
		s2.pop_back();
	}
}

void printVector(vi v){
	cout<<"[";
	for(int i=0;i<v.size();i++){
		if(i<v.size()-1) cout<<v[i]<<", ";
		else cout<<v[i];
	}
	cout<<"] ";
}

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vi s1,s2;
	int x = n/2;
	int y = n-x;
	solver(arr,n,0,s1,s2,y,x);
	printVector(fs1);
	printVector(fs2);
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