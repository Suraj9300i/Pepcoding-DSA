#include<iostream>
#include<map>

using namespace std;

void solve(string str,int i,char ans[],int n,map<char,int> mp,int c){
   if(i==n){
   	if(c==n){
   		for(int j=0;j<n;j++)
   			cout<<ans[j];
   		cout<<endl;
   	}
   	return;
   }
   for(int j=mp[str[i]]+1;j<n;j++){
   	if(ans[j]==NULL){
   		ans[j] = str[i];
   		int x = mp[str[i]];
   		mp[str[i]] = j;
   		solve(str,i+1,ans,n,mp,c+1);
   		ans[j] = NULL;
   		mp[str[i]] = x;
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
    char ans[n] = {NULL};
    for(char ch:str){
        mp[ch] = -1;
    }
    solve(str,0,ans,n,mp,0);
    return 0;
}