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
int mxs = 0;
void solver(string words[],int n,int score[],map<char,int> mp,int ts){
	if(n<0){
		mxs = max(mxs,ts);
		return;
	}
	solver(words,n-1,score,mp,ts);
	bool isPossible = true;
	int cs = 0;
	for(char ch:words[n]){
		mp[ch]--;
		cs += score[ch-'a'];
		if(mp[ch]<0){
			isPossible = false;
		}
	}
	if(isPossible){
		solver(words,n-1,score,mp,ts+cs);
	}
	for(char ch:words[n]){
		mp[ch]++;
	}
}

void solve(){
	int n,m;
	cin>>n;
	string words[n];
	for(int i=0;i<n;i++)
		cin>>words[i];
	cin>>m;
	map<char,int> mp;
	char ch;
	for(int i=0;i<m;i++){
		cin>>ch;
		mp[ch]++;
	}
	int score[26];
	for(int i=0;i<26;i++){
		cin>>score[i];
	}
	solver(words,n-1,score,mp,0);
	cout<<mxs;
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