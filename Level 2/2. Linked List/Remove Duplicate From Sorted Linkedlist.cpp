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

ListNode *removeDuplicates(ListNode *head)
{
    ListNode* temp = head;
    ListNode* dummy = new ListNode(-1);
    ListNode* dt = dummy;
    while(temp!=NULL){
        if(temp->val==dt->val){
            temp = temp->next;
            continue;
        }
        dt->next = temp;
        temp = temp->next;
        dt = dt->next;
    }
    dt->next = temp;
    return dummy->next;
}
// Input_code===================================================

ListNode *makeList(int n)
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
    ListNode *head = makeList(n);

    head = removeDuplicates(head);
    printList(head);

    return 0;
}