#include<iostream>

using namespace std;

void solve(int arr[],int n,int sum,int cur,string ans){
    if(sum==0){
        cout<<ans<<"."<<endl;
        return;
    }
    if(sum<0 || cur>=n) return;
    solve(arr,n,sum-arr[cur],cur,ans+to_string(arr[cur])+"-");
    solve(arr,n,sum,cur+1,ans);
}

int main(){
    int n,k;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>k;
    
    solve(arr,n,k,0,"");
    
    return 0;
}