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

ListNode *midNode(ListNode *head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    head = slow;
    return head;
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

    ListNode *head = midNode(dummy->next);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}