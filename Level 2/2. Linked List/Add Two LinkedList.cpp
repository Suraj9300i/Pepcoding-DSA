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
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;
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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    l1 = reverse(l1);
    l2 = reverse(l2);
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    ListNode* t1 = l1;
    ListNode* t2 = l2;
    int carry = 0;
    while(t1!=NULL or t2!=NULL or carry!=0){
        int sum = carry;
        if(t1!=NULL){
            sum += t1->val;
            t1 = t1->next;
        }
        if(t2!=NULL){
            sum += t2->val;
            t2 = t2->next;
        }
        if(sum>=10){
            carry = sum/10;
            sum %= 10;
        }
        else carry = 0;
        ListNode* nn = new ListNode(sum);
        temp->next = nn;
        temp = temp->next;
    }
    dummy = reverse(dummy->next);
    return dummy;
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
    ListNode *head1 = makeList(n);

    int m;
    cin >> m;
    ListNode *head2 = makeList(m);

    ListNode *head = addTwoNumbers(head1, head2);
    printList(head);

    return 0;
}