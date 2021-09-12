#include<iostream>
#include<map>

using namespace std;

void solve(string str,int n,int k,map<char,int> mp,int ci,string ans){
    if(ci==n){
        if(ans.size()==k){
            cout<<ans<<endl;
        }
        return;
    }
    int f = mp[str[ci]];
    for(int i=f;i>=0;i--){
        string temp = "";
        for(int j=0;j<i;j++)
            temp.push_back(str[ci]);
        solve(str,n,k,mp,ci+1,ans+temp);
    }
}

int main(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    
    map<char,int> mp;
    string unq = "";
    for(char ch:str){
        if(mp.find(ch)==mp.end()){
            unq.push_back(ch);
        }
        mp[ch]++;
    }
    solve(unq,unq.size(),k,mp,0,"");
    return 0;
}