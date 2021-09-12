#include<iostream>

using namespace std;

void solve(int arr[],int n,int sum,bool used[],string ans){
    if(sum==0){
        cout<<ans<<"."<<endl;
        return;
    }
    if(sum<0) return;
    for(int i=0;i<n;i++){
        if(!used[i]){
            used[i] = true;
            solve(arr,n,sum-arr[i],used,ans+to_string(arr[i])+"-");
            used[i] = false;
        }
    }
}

int main(){
    int n,k;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>k;
    bool used[n] = {false};
    solve(arr,n,k,used,"");
    
    return 0;
}