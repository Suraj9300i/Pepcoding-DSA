#include <bits/stdc++.h>
using namespace std;

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
  }

  dll.display();

  return 0;
}