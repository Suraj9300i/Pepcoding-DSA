#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode* getMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* cur = head;
    while(cur!=NULL){
        ListNode* fwd = cur->next;
        cur->next = prev;
        prev = cur;
        cur = fwd;
    }
    head = prev;
    return head;
}
void display(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
bool isPalindrome(ListNode* head) {
    if(head==NULL || head->next==NULL)
        return true;
    ListNode* mid = getMid(head);
    ListNode* t1 = head;
    ListNode* t2 = reverse(mid->next);
    while(t2!=NULL){
        if(t1->val!=t2->val)
            return false;
        t1 = t1->next;
        t2 = t2->next;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }

    cout << (boolalpha) << isPalindrome(dummy->next) << endl;

    return 0;
}