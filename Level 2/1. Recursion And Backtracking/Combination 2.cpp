#include<iostream>

using namespace std;

void solve(char boxes[],int n,int k,int item,int b){
    if(b>=n-1 || item>=k){
        if(item==k){
            for(int i=0;i<n;i++)
                cout<<boxes[i];
            cout<<endl;
        }
        return;
    }
    
    for(int i=b+1;i<n;i++){
        if(boxes[i]=='-'){
            boxes[i] = 'i';
            solve(boxes,n,k,item+1,i);
            boxes[i] = '-';
        }
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    char boxes[n];
    for(int i=0;i<n;i++)
        boxes[i] = '-';
    solve(boxes,n,k,0,-1);
    
    return 0;
}