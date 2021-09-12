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
    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
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
    return prev;
}

void fold(ListNode* head) {
    if(head==NULL) return;
    ListNode* mid = getMid(head);
    ListNode* t2 = reverse(mid->next);
    ListNode* t1 = head;
    while(t2!=NULL){
        ListNode* ft1 = t1->next;
        ListNode* ft2 = t2->next;
        t1->next = t2;
        t2->next = ft1;
        t1 = ft1;
        t2 = ft2;
    }
    t1->next = NULL;
}

void printList(ListNode *node)
{
    ListNode *curr = node;
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
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }

    ListNode *head = dummy->next;
    fold(head);
    printList(head);

    return 0;
}