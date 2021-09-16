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
template<class T> void _print(vector<T> v){cerr<<"[ ";for(T ele:v) cerr<<ele<<" "; cerr<<"]\n";}
template<class T> void _print(T arr[],int n){cerr<<"[ ";for(int i=0;i<n;i++) cerr<<arr[i]<<" "; cerr<<"]\n";}

/***************************Jay Shree Ram****************************/

priority_queue<int> mxh;
priority_queue<int,vector<int>,greater<int>> mnh;

void add(int val) {
	if(mxh.size()==0) mnh.push(val);
	else if(val<mnh.top()) mxh.push(val);
	else mnh.push(val);

	if(mxh.size()-mnh.size()==2){
		int temp = mxh.top();
		mxh.pop();
		mnh.push(temp);
	}
	if(mnh.size()-mxh.size()==2){
		int temp = mnh.top();
		mnh.pop();
		mxh.push(temp);
	}
}

int remove() {
	int x = mxh.size();
	int y = mnh.size();
	if(x==0 && y==0){
		cout<<"Underflow\n";
		return -1;
	}
	else if(x>=y){
		int val = mxh.top();
		mxh.pop();
		return val;
	}
	else{
		int val = mnh.top();
		mnh.pop();
		return val;
	}
}

int peek() {
	int x = mxh.size();
	int y = mnh.size();
	if(x==0 && y==0){
		cout<<"Underflow\n";
		return -1;
	}
	else if(x>=y) return mxh.top();
	else return mnh.top();
}

int size() {
	return mxh.size()+mnh.size();
}

void solve(){
	string str;
	while(true){
		getline(cin,str);
		if(str=="quit") break;
		else if(str=="peek"){
			int val = peek();
			if(val!=-1){
				cout<<val<<endl;
			}
		}
		else if(str=="remove"){
			int val = remove();
			if(val!=-1){
				cout<<val<<endl;
			}
		}
		else if(str=="size"){
			cout<<(size())<<endl;
		}
		else{
			string num = "";
			for(char ch:str){
				if(ch>='0' && ch<='9'){
					num.push_back(ch);
				}
			}
			add(stoi(num));
		}
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