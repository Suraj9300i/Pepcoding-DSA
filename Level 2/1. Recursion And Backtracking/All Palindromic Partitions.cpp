#include<iostream>
#include<vector>

using namespace std;

bool isPalindrome(string str){
    int s = 0;
    int e = str.size()-1;
    while(s<e){
        if(str[s]!=str[e])
            return false;
        s++,e--;
    }
    return true;
}

void solve(string str,int n,int i,vector<string> ans){
    if(i>=n){
        for(string ele:ans){
            cout<<"("<<ele<<") ";
        }
        cout<<endl;
        return;
    }
    string temp = "";
    for(int j=i;j<n;j++){
        temp.push_back(str[j]);
        if(isPalindrome(temp)){
            ans.push_back(temp);
            solve(str,n,j+1,ans);
            ans.pop_back();
        }
    }
}

int main(){
    string str;
    cin>>str;
    int n = str.size();
    vector<string> ans;
    solve(str,n,0,ans);
    
    return 0;
}