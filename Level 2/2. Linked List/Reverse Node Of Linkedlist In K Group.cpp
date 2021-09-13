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

ListNode* reverseInKGroup(ListNode* head, int k)
{
  int s = size(head);
  if(k==0 or k>s) return head;
  ListNode* fh = NULL;
  ListNode* ft = NULL;
  ListNode* temp = head;
  while(s>=k){
      ListNode* ch = NULL;
      ListNode* ct = NULL;
      for(int i=0;i<k;i++){
          ListNode* fwd = temp->next;
          temp->next = NULL;
          if(ch==NULL){
              ch = temp;
              ct = temp;
          }
          else{
              temp->next = ch;
              ch = temp;
          }
          temp = fwd;
          s--;
      }
      if(fh==NULL){
          fh = ch;
          ft = ct;
      }
      else{
          ft->next = ch;
          ft = ct;
      }
  }
  if(s>0){
      ft->next = temp;
  }
  return fh;
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
  int k;
  cin >> k;
  h1 = reverseInKGroup(h1, k);
  printList(h1);

  return 0;
}