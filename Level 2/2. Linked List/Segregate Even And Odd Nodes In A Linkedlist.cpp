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

void print(ListNode* temp){
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

ListNode *segregateEvenOdd(ListNode *head)
{
    ListNode* even = new ListNode(-1);
    ListNode* evenH = even;
    ListNode* odd = new ListNode(-1);
    ListNode* oddH = odd;
    ListNode* temp = head;
    while(temp!=NULL){
        if(temp->val%2==0){
            even->next = temp;
            even = even->next;
        }
        else{
            odd->next = temp;
            odd = odd->next;
        }
        temp = temp->next;
    }
    even->next = NULL;
    odd->next = NULL;
    if(evenH->next==NULL) return oddH->next;
    else if(oddH->next==NULL) return evenH->next;
    else{
        even->next = oddH->next;
        return evenH->next;
    }
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

    ListNode *head = segregateEvenOdd(dummy->next);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}