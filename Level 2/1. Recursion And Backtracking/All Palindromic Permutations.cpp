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
void solver(string unq,int n,map<char,int> mp,bool isOdch,char odch,string per){
	if(n<=0){
		cout<<per;
		if(isOdch) cout<<odch;
		reverse(per.begin(), per.end());
		cout<<per<<endl;
		return;
	}
	for(char ch:unq){
		if(mp[ch]>0){
			mp[ch]--;
			solver(unq,n-1,mp,isOdch,odch,per+ch);
			mp[ch]++;
		}
	}
}

void solve(){
	string str;
	cin>>str;
	map<char,int> mp;
	string unq = "";
	for(char ch:str){
		if(mp.find(ch)==mp.end()){
			unq.push_back(ch);
		}
		mp[ch]++;
	}
	int odc = 0;
	char odch;
	for(auto it:mp){
		if(it.second&1){
			odc++;
			odch = it.first;
		}
		mp[it.first] = it.second/2;
	}
	if(odc>1) cout<<"-1";
	else{
		bool isOdch = odc&1;
		solver(unq,str.size()/2,mp,isOdch,odch,"");
	}
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