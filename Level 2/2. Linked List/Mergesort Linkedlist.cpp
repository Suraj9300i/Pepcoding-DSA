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

ListNode* merge(ListNode* l1,ListNode* l2){
    ListNode* t1 = l1;
    ListNode* t2 = l2;
    ListNode* dmy = new ListNode(-1);
    ListNode* tail = dmy;
    while(t1!=NULL && t2!=NULL){
        if(t1->val<t2->val){
            tail->next = t1;
            t1 = t1->next;
        }
        else{
            tail->next = t2;
            t2 = t2->next;
        }
        tail = tail->next;
    }
    if(t1!=NULL) tail->next = t1;
    if(t2!=NULL) tail->next = t2;
    return dmy->next;
}

ListNode* getMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *mergeSort(ListNode *head)
{
    if(head->next==NULL)
        return head;
    ListNode* mid = getMid(head);
    ListNode* fwd = mid->next;
    mid->next = NULL;
    ListNode* left = mergeSort(head);
    ListNode* right = mergeSort(fwd);
    ListNode* m = merge(left,right);
    return m;
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

ListNode *createList(int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
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
    ListNode *h1 = createList(n);

    ListNode *head = mergeSort(h1);
    printList(head);

    return 0;
}