#include <iostream>
using namespace std;

class ListNode
{
public:
  int val = 0;
  ListNode* next = nullptr;

  ListNode(int val)
  {
    this->val = val;
  }
};

int size(ListNode* head){
    int c = 0;
    while(head!=NULL){
        head = head->next;
        c++;
    }
    return c;
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    int s = size(head);
    if(n>s) return head;
    int c = 1;
    int r = s-n+1;
    ListNode* temp = head;
    ListNode* p1 = NULL;
    ListNode* p2 = NULL;
    while(temp!=NULL){
        if(c<r){
            p1 = temp;
        }
        else if(c>r){
            p2 = temp;
            break;
        }
        temp = temp->next;
        c++;
    }
    if(p1==NULL) return head->next;
    p1->next = p2;
    return head;
}

void printList(ListNode* node)
{
  ListNode* curr = node;
  while (curr != nullptr)
  {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}

ListNode* createList(int n)
{
  ListNode* dummy = new ListNode(-1);
  ListNode* prev = dummy;
  while (n-- > 0)
  {
    int val;
    cin >> val;
    prev->next = new ListNode(val);
    prev = prev->next;
  }
  return dummy->next;
}

int main()
{
  int n;
  cin >> n;
  ListNode* h1 = createList(n);
  int m;
  cin >> m;
  h1 = removeNthFromEnd(h1, m);
  printList(h1);

  return 0;
}