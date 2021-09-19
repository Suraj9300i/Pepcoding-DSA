#include<bits/stdc++.h>
#define ff first
#define ss second
#define ll long long int
#define mod 1000000007
#define debug(x) cerr<<#x<<" :- ";_print(x);cerr<<endl;
#define debugArray(x,y) cerr<<#x<<" :- ";_print(x,y);cerr<<endl;
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
void fastIO(){
  #ifndef ONLINE_JUDGE 
  freopen("Error.txt","w",stderr);
  #endif
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
}
template<class T> void _print(T x){cerr<<x;}
template<class T> void _print(vector<T> v){cerr<<"[ ";for(T ele:v) cerr<<ele<<" "; cerr<<"]\n";}
template<class T> void _print(T arr[],int n){cerr<<"[ ";for(int i=0;i<n;i++) cerr<<arr[i]<<" "; cerr<<"]\n";}

/***************************Jay Shree Ram****************************/

class LRUCache {
    class Node{
    public:
      int key;
      int value;
      Node* prev;
      Node* next;
      Node(){};
      Node(int x,int y){
        key = x;
        value = y;
        prev = NULL;
        next = NULL;
      }
    };

    map<int,Node*> mp;
    Node* head;
    Node* tail;
    int capacity;
    int sizee;

    void addLast(Node* node){
      if(head==NULL){
        head = tail = node;
      }
      else{
        tail->next = node;
        node->prev = tail;
        tail = node;
      }
      sizee++;
    }

    Node* removeFirst(){
      if(head==NULL)
        return NULL;
      Node* temp = head;
      head = head->next;
      if(head!=NULL) head->prev = NULL;
      temp->next = NULL;
      temp->prev = NULL;
      sizee--;
      return temp;
    }

    Node* remove(Node* node){
      if(head==NULL || node==NULL)
        return NULL;
      if(head==node)
        return removeFirst();
      if(tail==node){
        Node* bck = node->prev;
        bck->next = NULL;
        node->prev = NULL;
        tail = bck;
      }
      else{
        Node* bck = node->prev;
        Node* fwd = node->next;
        bck->next = fwd;
        fwd->prev = bck;
        node->next = NULL;
        node->prev = NULL;
      }
      sizee--;
      return node;
    }
    
public:
    LRUCache(int c) {
        head = NULL;
        tail = NULL;
        capacity = c;
        sizee = 0;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
          return -1;
        Node* node = mp[key];
        remove(node);
        addLast(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
          Node* node = mp[key];
          remove(node);
          addLast(node);
          node->value = value;
        }
        else{
          Node* nn = new Node(key,value);
          addLast(nn);
          mp[key] = nn;
          if(sizee>capacity){
            Node* n = removeFirst();
            mp.erase(n->key);
          }
        }
    }
};

int main(){
  string str;
  int n,k;

  LRUCache* obj;
  while(true){
    cin>>str;
    if(str=="start"){
      cin>>n;
      obj = new LRUCache(n);
    }
    else if(str=="put"){
      cin>>n>>k;
      obj->put(n,k);
    }
    else if(str=="get"){
      cin>>n;
      cout<<(obj->get(n))<<endl;
    }
    else if(str=="stop"){
      break;
    }
  }

  return 0;
}

