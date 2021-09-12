#include<iostream>
#include<map>

using namespace std;

void solve(string str,int n,int k,map<char,int> mp,int li,string ans){
    if(k==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=li+1;i<n;i++){
        if(mp[str[i]]>0){
            mp[str[i]]--;
            solve(str,n,k-1,mp,i-1,ans+str[i]);
            mp[str[i]]++;
        }
    }
}

int main(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    
    string unq = "";
    map<char,int> mp;
    for(char ch:str){
        if(mp.find(ch)==mp.end())
            unq.push_back(ch);
        mp[ch]++;
    }
    solve(unq,unq.size(),k,mp,-1,"");
    return 0;
}