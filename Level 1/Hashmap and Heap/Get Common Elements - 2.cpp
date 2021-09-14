#include<iostream>
#include<map>

using namespace std;

int main(){
    int n1,n2;
    cin>>n1;
    int ar1[n1];
    map<int,int> mp;
    for(int i=0;i<n1;i++){
        cin>>ar1[i];
        mp[ar1[i]]++;
    }
    cin>>n2;
    int ar2[n2];
    for(int i=0;i<n2;i++){
        cin>>ar2[i];
        if(mp[ar2[i]]>0){
            cout<<ar2[i]<<endl;
            mp[ar2[i]]--;
        }
    }
    
    return 0;
}