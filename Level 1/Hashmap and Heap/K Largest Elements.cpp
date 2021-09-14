#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n,k;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    
    priority_queue<int,vector<int>,greater<int>> mxh;
    for(int i=0;i<n;i++){
        mxh.push(arr[i]);
        if(mxh.size()>k){
            mxh.pop();
        }
    }
    
    while(!mxh.empty()){
        cout<<mxh.top()<<endl;
        mxh.pop();
    }
    
    return 0;
}