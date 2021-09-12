#include<iostream>

using namespace std;

void solve(char boxes[],int n,int k,int box,int ssf){
    if(box>=n){
        if(ssf==k){
            for(int i=0;i<n;i++)
                cout<<boxes[i];
            cout<<endl;
        }
        return;
    }
    
    boxes[box] = 'i';
    solve(boxes,n,k,box+1,ssf+1);
    boxes[box] = '-';
    
    solve(boxes,n,k,box+1,ssf);
}

int main(){
    int n,k;
    cin>>n>>k;
    char boxes[n];
    solve(boxes,n,k,0,0);
    
    return 0;
}