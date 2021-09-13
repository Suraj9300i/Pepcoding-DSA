#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;
    ListNode *random = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode *copyRandomList(ListNode *head)
{
    return head;
}

int main()
{
    int n;
    cin >> n;

    vector<ListNode *> arr(n);
    ListNode *prev = nullptr;
    for (int i = 0; i < n; i++)
    {
        arr[i] = new ListNode(0);
        if (prev != nullptr)
            prev->next = arr[i];
        prev = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int val, idx;
        cin >> val >> idx;

        arr[i]->val = val;
        if (idx != -1)
            arr[i]->random = arr[idx];
    }

    ListNode *head = copyRandomList(arr[0]);
    while (head != nullptr)
    {
        cout << "(" + to_string(head->val) + ", " + (head->random != nullptr ? to_string(head->random->val) : to_string(-1)) + ") ";
        head = head->next;
    }
    return 0;
}