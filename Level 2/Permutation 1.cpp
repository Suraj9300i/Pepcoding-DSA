#include<bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define mod 1000000007
using namespace std;
void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
void setupIO(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
/*************************Jay Shree Ram**************************/

void permutation1(int boxes[],int item,int n,int k){
	if(item>k){
		for(int i=0;i<n;i++)
			cout<<boxes[i];
		cout<<endl;
		return;
	}
	for(int i=0;i<n;i++){
		if(boxes[i]==0){
			boxes[i] = item;
			permutation1(boxes,item+1,n,k);
			boxes[i] = 0;
		}
	}
}

void solve(){
	int n,k;
	cin>>n>>k;
	int boxes[n] = {0};
	permutation1(boxes,1,n,k);
}

int main(){
	fastIO();
// 	setupIO();
	
	int t = 1;
	// cin>>t;
	while(t--){
		solve();
	}

return 0;
}