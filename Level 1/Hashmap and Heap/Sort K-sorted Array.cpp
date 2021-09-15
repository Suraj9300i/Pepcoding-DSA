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
    
    priority_queue<int,vector<int>,greater<int>> mnh;
    int i=0;
    for(;i<=k;i++){
        mnh.push(arr[i]);
    }
    for(;i<n;i++){
        cout<<mnh.top()<<endl;
        mnh.pop();
        mnh.push(arr[i]);
    }
    while(!mnh.empty()){
        cout<<mnh.top()<<endl;
        mnh.pop();
    }
    
    return 0;
}