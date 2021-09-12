#include<iostream>
#include<map>

using namespace std;

void solve(string str,int n,int k,map<char,int> mp,int si,char ans[],int ac){
    if(si==n){
        if(ac==k){
            for(int i=0;i<k;i++)
                cout<<ans[i];
            cout<<endl;
        }
        return;
    }
    int x = mp[str[si]];
    for(int i=x+1;i<k;i++){
        if(ans[i]==0){
            ans[i] = str[si];
            int temp = mp[str[si]];
            mp[str[si]] = i;
            solve(str,n,k,mp,si+1,ans,ac+1);
            ans[i] = 0;
            mp[str[si]] = temp;
        }
    }
    if(x==-1){
        solve(str,n,k,mp,si+1,ans,ac);
    }
}

int main(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    
    map<char,int> mp;
    for(char ch:str){
        mp[ch] = -1;
    }
    char ans[k];
    for(int i=0;i<k;i++) ans[i] = 0;
    solve(str,str.size(),k,mp,0,ans,0);

    return 0;
}