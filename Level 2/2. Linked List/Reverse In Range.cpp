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

ListNode *reverseInRange(ListNode *head, int left, int right)
{
            ListNode* p1 = NULL;        
        ListNode* p2 = NULL;
        ListNode* temp = head;
        ListNode* rh = NULL;
        ListNode* rt = NULL;
        int c = 1;
        while(temp!=NULL){
            if(c<left){
                p1 = temp;
                temp = temp->next;
            }
            else if(c>=left && c<=right){
                ListNode* fwd = temp->next;
                temp->next = NULL;
                if(rh==NULL){
                    rh = temp;
                    rt = temp;
                }
                else{
                    temp->next = rh;
                    rh = temp;
                }
                temp = fwd;
            }
            else{
                p2 = temp;
                break;
            }
            c++;
        }
        if(p1==NULL) head = rh;
        else p1->next = rh;
        rt->next = p2;
        return head;
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
    int m;
    cin >> m >> n;
    h1 = reverseInRange(h1, m, n);
    printList(h1);

    return 0;
}