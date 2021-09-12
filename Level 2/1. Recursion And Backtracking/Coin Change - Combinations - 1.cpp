#include <iostream>

using namespace std;

void solve(int arr[],int n,int tSum,int cur,int cSum,string op){
	if(cur==n){
		if(cSum==tSum)
			cout<<op<<".\n";
		return;
	}
	solve(arr,n,tSum,cur+1,cSum+arr[cur],op+to_string(arr[cur])+"-");
	solve(arr,n,tSum,cur+1,cSum,op);
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,sum;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>sum;	
	solve(arr,n,sum,0,0,"");
	return 0;
}



