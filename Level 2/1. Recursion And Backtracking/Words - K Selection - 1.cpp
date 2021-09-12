#include<iostream>
#include<map>

using namespace std;

void solve(string str,int n,int k,int ind,string ans,int c){
    if(ind==n){
        if(c==k) cout<<ans<<endl;
        return;
    }
    solve(str,n,k,ind+1,ans+str[ind],c+1);
    solve(str,n,k,ind+1,ans,c);
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int n,k;
    string str;
    cin>>str;
    cin>>k;
    n = str.size();
    string unq = "";
    map<char,int> mp;
    for(char ch:str){
        if(mp.find(ch)==mp.end()){
            mp[ch]++;
            unq.push_back(ch);
        }
    }
    solve(unq,unq.size(),k,0,"",0);
    
    return 0;
}