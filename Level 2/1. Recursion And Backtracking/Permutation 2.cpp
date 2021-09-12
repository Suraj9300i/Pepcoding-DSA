#include<iostream>

using namespace std;

void solve(int boxes[],int n,int k,bool used[],int box,int x){
    if(box>=n){
        if(x==k){
            for(int i=0;i<n;i++)
                cout<<boxes[i];
            cout<<endl; 
        }
        return;
    }
    for(int i=1;i<=k;i++){
        if(!used[i]){
            used[i] = true,boxes[box] = i;
            solve(boxes,n,k,used,box+1,x+1);
            boxes[box] = 0,used[i] = false;
        }
    }
    solve(boxes,n,k,used,box+1,x);
}

int main(){
    int n,k;
    cin>>n>>k;
    int boxes[n] = {0};
    bool used[k+1] = {0};
    solve(boxes,n,k,used,0,0);
    
    return 0;
}