#include<iostream>
#include<map>

using namespace std;

int main(){
    int n;
    cin>>n;
    int ar[n];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>ar[i];
        mp[ar[i]] = 0;
    }
    int st = 0;
    int mx = 0;
    for(int i=0;i<n;i++){
        if(mp.find(ar[i]-1)==mp.end()){
            int c = 1;
            int x = ar[i]+1;
            while(mp.find(x)!=mp.end()){
                x++;
                c++;
            }
            if(c==mx){
                if(ar[i]<st){
                    st = ar[i];
                    mx = c;
                }
            }
            else if(c>mx){
                st = ar[i];
                mx = c;
            }
        }
    }
    for(int i=0;i<mx;i++){
        cout<<(st+i)<<endl;
    }
    
    return 0;
}