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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode* t1 = l1;
    ListNode* t2 = l2;
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    while(t1!=NULL && t2!=NULL){
        if(t1->val<t2->val){
            temp->next = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            t2 = t2->next;
        }
        temp = temp->next;
    }
    if(t1!=NULL) temp->next = t1;
    if(t2!=NULL) temp->next = t2;
    return dummy->next;
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
    int n, m;
    cin >> n ;
    ListNode *h1 = createList(n);
    cin >> m;
    ListNode *h2 = createList(m);

    ListNode *head = mergeTwoLists(h1, h2);
    printList(head);

    return 0;
}