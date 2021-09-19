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

class DoublyLinkedList
{
  class Node
  {
  public:
    int data = 0;
    Node* prev = nullptr;
    Node* next = nullptr;

    Node(int data)
    {
      this->data = data;
    }
  };

  Node* head = nullptr;
  Node* tail = nullptr;
  int size = 0;

public:
  void display()
  {
    string str = "";
    Node* curr = this->head;
    str += "[";
    while (curr != nullptr)
    {
      str += to_string(curr->data);
      if (curr->next != nullptr)
        str += ", ";
      curr = curr->next;
    }
    str += "]";

    cout << str << endl;
  }

private:
  void addFirstNode(Node* node)
  {
    if (this->size == 0)
      this->head = this->tail = node;
    else
    {
      node->next = this->head;
      this->head->prev = node;
      this->head = node;
    }
    this->size++;
  }

public:
  void addFirst(int data)
  {
    Node* node = new Node(data);
    addFirstNode(node);
  }

  void addLast(int data)
  {
      Node* nn = new Node(data);
      if(head==NULL){
          head = tail = nn;
      }
      else{
          tail->next = nn;
          nn->prev = tail;
          tail = nn;
      }
      size++;
  }

    void addAt(int index, int data) {
        if(index<0 or index>size){
            cout<<"IndexIsInValid: -1\n";
            return;
        }
        if(index==0){
            addFirst(data);
        }
        else if(index==size){
            addLast(data);
        }
        else{
            Node* nn = new Node(data);
            Node* t1 = head;
            for(int i=0;i<index-1;i++){
                t1 = t1->next;
            }
            Node* t2 = t1->next;
            t1->next = nn;
            nn->next = t2;
            nn->prev = t1;
            t2->prev = nn;
            size++;
        }
    }

    void addBefore(int idx, int data) {
        if(idx<0 or idx>=size){
            cout<<"IndexIsInValid: -1"<<endl;
        }
        else if(size==0){
            cout<<"ListIsEmpty: -1"<<endl;
        }
        else if(idx==0){
            addFirst(data);
        }
        else{
            Node* temp = head;
            for(int i=0;i<idx-1;i++){
                temp = temp->next;
            }
            Node* fwd = temp->next;
            Node* nn = new Node(data);
            temp->next = nn;
            nn->prev = temp;
            nn->next = fwd;
            fwd->prev = nn;
            size++;
        }
    }

    void addAfter(int idx, int data){
        if(idx<0 or idx>=size){
            cout<<"IndexIsInValid: -1"<<endl;
        }
        else if(size==0){
            cout<<"ListIsEmpty: -1"<<endl;
        }
        else if(idx==size-1){
            addLast(data);
        }
        else{
            Node* temp = head;
            for(int i=0;i<idx;i++){
                temp = temp->next;
            }
            Node* fwd = temp->next;
            Node* nn = new Node(data);
            temp->next = nn;
            nn->prev = temp;
            nn->next = fwd;
            fwd->prev = nn;
            size++;
        }
    }

    int removeFirst() {
        if(size==0){
            cout<<"ListIsEmpty: ";
            return -1;
        }
        Node* cur = head;
        if(head->next==NULL){
            head = NULL;
            tail = NULL;
        }
        else{
            Node* fwd = cur->next;
            cur->next = NULL;
            fwd->prev = NULL;
            head = fwd;
        }
        size--;
        return cur->data;
    }

    int removeLast() {
        if(size==0){
            cout<<"ListIsEmpty: ";
            return -1;
        }
        int cur = tail->data;
        if(head->next==NULL){
            head = tail = NULL;
        }
        else{
            Node* bck = tail->prev;
            tail->prev = NULL;
            bck->next = NULL;
            tail = bck;
        }
        size--;
        return cur;
    }

    int removeAt(int index) {
      if(index<0 or index>=size){
        cout<<"IndexIsInValid: ";
        return -1;
      }
      else if(index==0){
        return removeFirst();
      }
      else if(index==size-1){
        return removeLast();
      }
      else{
        Node* cur = head;
        for(int i=0;i<index;i++){
          cur = cur->next;
        }
        Node* bck = cur->prev;
        Node* fwd = cur->next;
        bck->next = fwd;
        fwd->prev = bck;
        size--;
        return cur->data;
      }
    }

    int removeBefore(int idx){
        if(size==0){
            cout<<"ListIsEmpty: ";
            return -1;
        }
        else if(idx<0 or idx >=size){
            cout<<"IndexIsInValid: ";
            return -1;
        }
        else if(idx==0){
            cout<<"LocationIsInvalid: ";
            return -1;
        }
        else{
            Node* temp = head;
            for(int i=0;i<idx-1;i++){
                temp = temp->next;
            }
            Node* bck = temp->prev;
            Node* fwd = temp->next;
            if(bck!=NULL)bck->next = fwd;
            fwd->prev = bck;
            size--;
            if(bck==NULL){
                head = fwd;
            }
            temp->next = NULL;
            temp->prev = NULL;
            return temp->data;
        }
    }

    int removeAfter(int idx){
        if(size==0){
            cout<<"ListIsEmpty: ";
            return -1;
        }
        else if(idx<0 or idx >=size){
            cout<<"IndexIsInValid: ";
            return -1;
        }
        else if(idx==size-1){
            cout<<"LocationIsInvalid: ";
            return -1;
        }
        else{
            Node* bck = head;
            for(int i=0;i<idx;i++){
                bck = bck->next;
            }
            Node* temp = bck->next;
            Node* fwd = temp->next;
            bck->next = fwd;
            if(fwd!=NULL)fwd->prev = bck;
            if(fwd==NULL){
                tail = temp;
            }
            size--;
            temp->next = NULL;  
            temp->prev = NULL;
            return temp->data;
        }
    }

    int Size(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }

    int getFirst() {
        if(isEmpty()){
            cout<<"ListIsEmpty: ";
            return -1;
        }
        return head->data;
    }

    int getLast() {
        if(isEmpty()){
            cout<<"ListIsEmpty: ";
            return -1;
        }
        return tail->data;
    }

    int getAt(int index) {
        if(isEmpty()){
            cout<<"ListIsEmpty: ";
            return -1;
        }
        if(index<0 || index>=size){
            cout<<"IndexIsInValid: ";
            return -1;
        }
        Node* temp = head;
        while(index>0){
            temp = temp->next;
            index--;
        }
        return temp->data;
    }

};

int main()
{
  DoublyLinkedList dll;
  string s;
  while (getline(cin, s))
  {
    stringstream ss(s);
    string word;
    ss >> word;
    if (word == "stop")
      break;
    if (word == "addFirst")
    {
      int data;
      ss >> data;
      dll.addFirst(data);
    }
    else if (word == "addLast")
    {
      int data;
      ss >> data;
      dll.addLast(data);
    }
    else if(word == "removeFirst"){
        cout<<(dll.removeFirst())<<endl;
    }
    else if(word == "removeLast"){
        cout<<(dll.removeLast())<<endl;
    }
    else if (word=="getFirst")
        cout<<(dll.getFirst())<<endl;
    else if (word=="getLast")
        cout<<(dll.getLast())<<endl;
    else if (word=="size")
        cout<<(dll.Size())<<endl;
    else if (word=="isEmpty")
        cout<<(dll.isEmpty()?"true":"false")<<endl;
    else if(word==("getAt")){
        int ind;
        ss>>ind;
        cout<<(dll.getAt(ind))<<endl;
    }
    else if(word=="addAt"){
        int ind,data;
        ss>>ind>>data;
        dll.addAt(ind,data);
    }
    else if (word=="removeAt"){
      int ind;
      ss>>ind;
      dll.removeAt(ind);
    }
    else if (word==("addBefore")){
        int ind,data;
        ss>>ind>>data;
        dll.addBefore(ind,data);
    }
    else if (word==("addAfter")){
        int ind,data;
        ss>>ind>>data;
        dll.addAfter(ind,data);
    }
    else if (word==("removeBefore")){
        int ind;
        ss>>ind;
        cout<<(dll.removeBefore(ind))<<endl;
    }
    else if (word==("removeAfter")){
        int ind;
        ss>>ind;
        cout<<(dll.removeAfter(ind))<<endl;
    }
  }

  dll.display();

  return 0;
}