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

void unfold(ListNode *head)
{
    ListNode* temp = head;
    ListNode* dmy1 = new ListNode(-1);
    ListNode* dmy2 = new ListNode(-1);
    ListNode* tail1 = dmy1;
    ListNode* tail2 = dmy2;
    bool flag = true;
    while(temp!=NULL){
        if(flag){
            tail1->next = temp;
            tail1 = tail1->next;
        }
        else{
            tail2->next = temp;
            tail2 = tail2->next;
        }
        flag = !flag;
        temp = temp->next;
    }
    tail1->next = NULL;
    tail2->next = NULL;
    ListNode* rev = reverse(dmy2->next);
    tail1->next = rev;
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
    unfold(head);
    printList(head);

    return 0;
}