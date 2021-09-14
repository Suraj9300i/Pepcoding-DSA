#include<iostream>
#include<set>

using namespace std;

int main(){
    int n1,n2;
    cin>>n1;
    int ar1[n1];
    set<int> s1;
    for(int i=0;i<n1;i++){
        cin>>ar1[i];
        s1.insert(ar1[i]);
    }
    cin>>n2;
    int ar2[n2];
    set<int> s2;
    for(int i=0;i<n2;i++){
        cin>>ar2[i];
        if(s1.find(ar2[i])!=s1.end()){
            if(s2.find(ar2[i])==s2.end()){
                cout<<ar2[i]<<endl;
                s2.insert(ar2[i]);
            }
        }
    }
    
    return 0;
}