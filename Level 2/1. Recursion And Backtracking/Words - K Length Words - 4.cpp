#include<iostream>
#include<map>

using namespace std;

void solve(string str,int n,int k,map<char,int> mp,string ans){
    if(k==0){
        cout<<ans<<endl;
        return;
    }
    for(char ch:str){
        if(mp[ch]>0){
            mp[ch]--;
            solve(str,n,k-1,mp,ans+ch);
            mp[ch]++;
        }
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
        if(mp.find(ch)==mp.end())
            unq.push_back(ch);
        mp[ch]++;
    }
    solve(unq,unq.size(),k,mp,"");
    
    return 0;
}