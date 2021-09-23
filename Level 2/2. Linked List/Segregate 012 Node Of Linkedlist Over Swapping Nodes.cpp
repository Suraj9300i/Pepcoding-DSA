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

ListNode *segregate012(ListNode *head)
{
    ListNode* zero = new ListNode(-1);
    ListNode* one = new ListNode(-1);
    ListNode* two = new ListNode(-1);
    ListNode* zt = zero;
    ListNode* ot = one;
    ListNode* tt = two;
    ListNode* temp = head;
    while(temp!=nullptr){
        if(temp->val==0){
            zt->next = temp;
            zt = zt->next;
        }
        else if(temp->val==1){
            ot->next = temp;
            ot = ot->next;
        }
        else{
            tt->next = temp;
            tt = tt->next;
        }
        temp = temp->next;
    }
    tt->next = nullptr;
    ot->next = two->next;
    zt->next = one->next;
    return zero->next;
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
    h1 = segregate012(h1);
    printList(h1);

    return 0;
}