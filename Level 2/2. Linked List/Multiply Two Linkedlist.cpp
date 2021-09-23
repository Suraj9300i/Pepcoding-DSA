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
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while(cur!=nullptr){
        ListNode* fwd = cur->next;
        cur->next =prev;
        prev = cur;
        cur = fwd;
    }
    return prev;
}

ListNode* multiplyBySingleNode(ListNode* head,int val){
    int carry = 0;
    ListNode* temp = head;
    ListNode* dummy = new ListNode(-1);
    ListNode* dt = dummy;
    while(temp!=nullptr){
        int mul = carry;
        mul += (temp->val*val);
        if(mul>=10){
            carry = mul/10;
            mul %= 10;
        }
        else carry = 0;
        dt->next = new ListNode(mul);
        dt = dt->next;
        temp = temp->next;
    }
    if(carry>0){
        dt->next = new ListNode(carry);
        dt = dt->next;
    }
        
    return dummy->next;
}

ListNode* addZeroNodeAtFirst(ListNode* head,int n){
    for(int i=0;i<n;i++){
        ListNode* nn = new ListNode(0);
        nn->next = head;
        head = nn;
    }
    return head;
}

ListNode* addTwoLL(ListNode* l1,ListNode* l2){
    int carry = 0;
    ListNode* dummy = new ListNode(-1);
    ListNode* dt = dummy;
    ListNode* t1 = l1;
    ListNode* t2 = l2;
    while(t1!=nullptr || t2!=nullptr || carry!=0){
        int sum = carry;
        if(t1!=nullptr){
            sum += t1->val;
            t1 = t1->next;
        }
        if(t2!=nullptr){
            sum += t2->val;
            t2 = t2->next;
        }
        if(sum>=10){
            carry = sum/10;
            sum %= 10;
        }
        else carry = 0;
        dt->next = new ListNode(sum);
        dt = dt->next;
    }
    return dummy->next;
}

ListNode *multiplyTwoLL(ListNode *l1, ListNode *l2)
{
    l1 = reverse(l1);
    l2 = reverse(l2);
    ListNode* sum = nullptr;
    ListNode* temp = l2;
    int c = 0;
    while(temp!=nullptr){
        ListNode* mul = multiplyBySingleNode(l1,temp->val);
        mul = addZeroNodeAtFirst(mul,c);
        // cout<<"MUL: ";
        // printList(mul);
        sum = addTwoLL(sum,mul);
        // cout<<"SUM: ";
        // printList(sum);
        // cout<<endl;
        c++;
        temp = temp->next;
    }
    sum = reverse(sum);
    
    return sum;
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

int main()
{
    int n;
    cin >> n;
    ListNode *head1 = makeList(n);

    int m;
    cin >> m;
    ListNode *head2 = makeList(m);

    ListNode *head = multiplyTwoLL(head1, head2);
    printList(head);

    return 0;
}