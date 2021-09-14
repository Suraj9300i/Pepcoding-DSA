#include<iostream>
#include<map>

using namespace std;

int main(){
    string str;
    cin>>str;
    
    map<char,int> mp;
    for(char ch:str){
        mp[ch]++;
    }
    int x = 0;
    char ans;
    for(auto it:mp){
        if(it.second>x){
            x = it.second;
            ans = it.first;
        }
    }
    cout<<ans;
    
    return 0;
}