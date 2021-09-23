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

ListNode* getTail(ListNode* head){
    while(head->next!=nullptr) head = head->next;
    return head;
}

ListNode *segregateOnLastIndex(ListNode *head)
{
    ListNode* small = new ListNode(-1);
    ListNode* big = new ListNode(-1);
    ListNode* st = small;
    ListNode* bt = big;
    ListNode* temp = head;
    ListNode* pivot = getTail(head);
    while(temp!=pivot){
        if(temp->val<=pivot->val){
            st->next = temp;
            st = st->next;
        }
        else{
            bt->next = temp;
            bt = bt->next;
        }
        temp = temp->next;
    }
    st->next = pivot;
    pivot->next = big->next;
    bt->next = nullptr;
    return pivot;
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
    h1 = segregateOnLastIndex(h1);
    printList(h1);

    return 0;
}