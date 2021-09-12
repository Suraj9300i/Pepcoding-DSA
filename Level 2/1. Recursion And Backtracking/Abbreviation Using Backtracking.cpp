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

void solver(string str,int n,int cur,string ans,int cn){
    if(cur==n){
        cout<<ans;
        if(cn!=0) cout<<cn;
        cout<<endl;
        return;
    }
    string yans;
    if(cn!=0) yans = ans+to_string(cn)+str[cur];
    else yans = ans+str[cur];
    solver(str,n,cur+1,yans,0);
    solver(str,n,cur+1,ans,cn+1);
}

void solve(){
    string str;
    cin>>str;
    solver(str,str.size(),0,"",0);
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