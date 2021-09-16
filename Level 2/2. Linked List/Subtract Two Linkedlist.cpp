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

ListNode* midNode(ListNode* head)
{
  if (head == nullptr || head->next == nullptr)
    return head;

  ListNode* slow = head;
  ListNode* fast = head;
  while (fast->next != nullptr && fast->next->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

ListNode* reverse(ListNode* head){
    ListNode* cur = head;
    ListNode* prev = NULL;
    while(cur!=NULL){
        ListNode* fwd = cur->next;
        cur->next = prev;
        prev = cur;
        cur = fwd;
    }
    return prev;
}

int size(ListNode* head){
    int c = 0;
    while(head!=NULL){
        c++;
        head = head->next;
    }
    return c;
}

int compare(ListNode* l1,ListNode* l2){
    int n = size(l1);
    int m = size(l2);
    if(n>m) return 1;
    if(m>n) return 2;
    while(l1!=NULL && l2!=NULL){
        if(l1->val>l2->val) return 1;
        if(l2->val>l1->val) return 2;
        l1 = l1->next;
        l2 = l2->next;
    }
    return 0;
}

ListNode* removeLeadingZeros(ListNode* head){
    while(head!=NULL && head->val==0){
        head = head->next;
    }
    return head;
}

ListNode* subtractTwoNumbers(ListNode* l1, ListNode* l2)
{
    l1 = reverse(l1);
    l2 = reverse(l2);
    int cmp = compare(l1,l2);
    if(cmp==0){
        return new ListNode(0);
    }
    if(cmp==2){
        swap(l1,l2);
    }
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    ListNode* t1 = l1;
    ListNode* t2 = l2;
    int borrow = 0;
    while(t1!=NULL){
        int diff = t1->val+borrow;
        if(t2!=NULL){
            diff -= t2->val;
            t2 = t2->next;
        }
        if(diff<0){
            diff += 10;
            borrow = -1;
        }
        else borrow = 0;
        ListNode* nn = new ListNode(diff);
        temp->next = nn;
        temp = temp->next;
        t1 = t1->next;
    }
    ListNode* ans = reverse(dummy->next);
    ans = removeLeadingZeros(ans);
    return ans;
}

// Input_code===================================================

ListNode* makeList(int n)
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

int main()
{
  int n;
  cin >> n;
  ListNode* head1 = makeList(n);

  int m;
  cin >> m;
  ListNode* head2 = makeList(m);

  ListNode* head = subtractTwoNumbers(head1, head2);
  printList(head);

  return 0;
}