#include<iostream>

using namespace std;

void solve(int arr[],int n,int sum,string ans){
    if(sum==0){
        cout<<ans<<"."<<endl;
        return;
    }
    if(sum<0) return;
    for(int i=0;i<n;i++){
        solve(arr,n,sum-arr[i],ans+to_string(arr[i])+"-");
    }
}

int main(){
    int n,k;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>k;
    solve(arr,n,k,"");
    
    return 0;
}