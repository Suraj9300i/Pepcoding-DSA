#include<iostream>
#include<map>

using namespace std;

void solve(int n,int box,map<char,int> mp,string ans){
    if(box==n){
        cout<<ans<<endl;
        return;
    }
    for(auto it:mp){
        char ch = it.first;
        int frq = it.second;
        if(frq>0){
            mp[ch]--;
            solve(n,box+1,mp,ans+ch);
            mp[ch]++;
        }
    }
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    string str;
    cin>>str;
    int n = str.size();
    map<char,int> mp;
    for(char ch:str){
        mp[ch]++;
    }
    solve(n,0,mp,"");
    return 0;
}