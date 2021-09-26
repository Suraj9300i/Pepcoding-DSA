#include <iostream>
#include <vector>
#include <queue>
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

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* dummy = new ListNode(-1);
    ListNode* dt = dummy;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mnh;
    for(int i=0;i<lists.size();i++){
        mnh.push({lists[i]->val,i});
    }
    while(!mnh.empty()){
        pair<int,int> cur = mnh.top();
        mnh.pop();
        dt->next = lists[cur.second];
        dt = dt->next;
        if(lists[cur.second]->next!=nullptr){
            int val = lists[cur.second]->next->val;
            lists[cur.second] = lists[cur.second]->next;
            mnh.push({val,cur.second});
        }
    }
    dt->next = nullptr;
    return dummy->next;
}

int main()
{
    int n,m;
    cin >> n;
    vector<ListNode*> lists(n);
    for(int i=0;i<n;i++){
        cin>>m;
        lists[i] = createList(m);
    }
    ListNode* ans = mergeKLists(lists);
    printList(ans);

    return 0;
}