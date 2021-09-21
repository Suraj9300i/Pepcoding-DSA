#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
    public:
    int ver;
    int wt;
    string path;
    Node(){}
    Node(int x,int y,string s){
        ver = x;
        wt = y;
        path = s;
    }
};

vector<pair<int,int>> gr[100001];

bool operator<(const Node& x,const Node& y){
    if(x.wt==y.wt)
        return x.path.size()<y.path.size();
    return x.wt>y.wt;
}

int main(){
    int n,m,u,v,wt,src;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v>>wt;
        gr[u].push_back({v,wt});
        gr[v].push_back({u,wt});
    }
    cin>>src;
    
    bool vis[n] = {0};
    priority_queue<Node> pq;
    pq.push(Node(src,0,to_string(src)));
    while(!pq.empty()){
        Node cur = pq.top();
        pq.pop();
        if(vis[cur.ver]) continue;
        vis[cur.ver] = true;
        cout<<cur.ver<<" via "<<cur.path<<" @ "<<cur.wt<<endl;
        for(pair<int,int> nbr:gr[cur.ver]){
            if(!vis[nbr.first]){
                pq.push(Node(nbr.first,nbr.second+cur.wt,cur.path+to_string(nbr.first)));
            }
        }
    }
    
    return 0;
}