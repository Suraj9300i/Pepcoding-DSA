#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define ll long long
#define mod 1000000007
#define debug(x) cerr<<#x<<" :- ";_print(x);cerr<<endl;
#define debugArray(x,y) cerr<<#x<<" :- ";_print(x,y);cerr<<endl;
using namespace std;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<vector<ll>> vvi;
void fastIO(){
	#ifndef ONLINE_JUDGE 
	freopen("Error.txt","w",stderr);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
}
template<class T> void _print(T x){cerr<<x<<endl;}
template<class T> void _print(vector<T> v){cerr<<"[ ";for(T ele:v) cerr<<ele<<" "; cerr<<"]";}
template<class T> void _print(T arr[],int n){cerr<<"[ ";for(int i=0;i<n;i++) cerr<<arr[i]<<" "; cerr<<"]";}
/*************************Jay Shree Ram**************************/

void wordsLength(string str,int n,int k,vb vis,int bx,string ans){
	if(bx==k){
		cout<<ans<<endl;
		return;
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vis[i] = true;
			wordsLength(str,n,k,vis,bx+1,ans+str[i]);
			vis[i] = false;
		}
	}
}

void solve(){
	string str;
	cin>>str;
	int k;
	cin>>k;
	set<char> st;
	string unq = "";
	for(char ch:str){
		if(st.find(ch)==st.end()){
			st.insert(ch);
			unq.push_back(ch);
		}
	}
	debug(unq);
	vb vis(unq.size(),false);
	wordsLength(unq,unq.size(),k,vis,0,"");
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