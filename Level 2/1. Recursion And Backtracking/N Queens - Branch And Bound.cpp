#include<iostream>

using namespace std;

void solve(int n,int r,bool col[],bool fwd[],bool bck[],string ans){
    if(r==n){
        cout<<ans<<"."<<endl;
        return;
    }
    for(int c=0;c<n;c++){
        if(!col[c] && !fwd[r+c] && !bck[r-c+n-1]){
            col[c] = true;
            fwd[r+c]=true,bck[r-c+n-1]=true;
            solve(n,r+1,col,fwd,bck,ans+to_string(r)+"-"+to_string(c)+", ");
            col[c] = false;
            fwd[r+c]=false,bck[r-c+n-1]=false;
        }
    }
}

int main(){
    int n;
    cin>>n;
    bool col[n] = {0};
    bool fwd[2*n-1] = {0};
    bool bck[2*n-1] = {0};
    solve(n,0,col,fwd,bck,"");
    
    return 0;
}