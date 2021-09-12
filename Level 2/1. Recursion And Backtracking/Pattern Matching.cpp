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
void solver(string s1,string s2,int n,int m,bool used[],map<char,string> mp,int x,int y){
	if(y==m){
		if(x==n){
			set<char> st;
			for(char ch:s2){
				if(st.find(ch)==st.end()){
					cout<<ch<<" -> "<<mp[ch]<<", ";
					st.insert(ch);
				}
			}
			cout<<".";
		}
		return;
	}
	if(used[s2[y]]){
		int len = mp[s2[y]].size();
		string sub = s1.substr(x,len);
		if(sub==mp[s2[y]]){
			solver(s1,s2,n,m,used,mp,x+len,y+1);
		}
		else return;
	}
	else{
		string temp = "";
		for(int i=x;i<n;i++){
			temp.push_back(s1[i]);
			mp[s2[y]] = temp;
			used[s2[y]] = true;
			solver(s1,s2,n,m,used,mp,i+1,y+1);
			used[s2[y]] = false;
		}
	}
}

void solve(){
	string s1,s2;
	cin>>s1>>s2;
	int n = s1.size();
	int m = s2.size();
	map<char,string> mp;
	bool used[200] = {0};
	solver(s1,s2,n,m,used,mp,0,0);
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