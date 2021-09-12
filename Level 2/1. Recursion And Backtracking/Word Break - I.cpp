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
void solver(string str,int n,int cur,set<string> st,string ans){
	if(cur==n){
		cout<<ans<<endl;
		return;
	}
	string temp = "";
	for(int i=cur;i<n;i++){
		temp.push_back(str[i]);
		if(st.find(temp)!=st.end()){
			solver(str,n,i+1,st,ans+temp+" ");
		}
	}
}

void solve(){
	int n;
	string str;
	cin>>n;
	set<string> st;
	for(int i=0;i<n;i++){
		cin>>str;
		st.insert(str);
	}
	cin>>str;
	solver(str,str.size(),0,st,"");
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