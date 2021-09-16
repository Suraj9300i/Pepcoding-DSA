#include<bits/stdc++.h>
#define ff first
#define ss second
#define ll long long int
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
class Node{
public:
	int data;
	int index;
	int list;
	Node(){}
	Node(int x,int y,int z){
		data = x;
		index = y;
		list = z;
	}
};

bool operator<(const Node& x,const Node& y){
	return x.data>y.data;
}

void solve(){
	int n,k;
	cin>>k;
	vector<int> arr[k];
	for(int i=0;i<k;i++){
		cin>>n;
		arr[i].resize(n);
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	priority_queue<Node> mnh;
	vector<int> ans;
	for(int i=0;i<k;i++){
		mnh.push(Node(arr[i][0],0,i));
	}
	while(!mnh.empty()){
		int data = mnh.top().data;
		int ind = mnh.top().index;
		int list = mnh.top().list;
		mnh.pop();
		ans.push_back(data);
		if(ind<arr[list].size()-1){
			mnh.push(Node(arr[list][ind+1],ind+1,list));
		}
	}
	for(int ele:ans){
		cout<<ele<<" ";
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