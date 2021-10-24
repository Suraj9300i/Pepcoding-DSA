#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val = 0;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int val)
    {
        this->val = val;
    }
};

Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->right!=nullptr && fast->right->right!=nullptr){
        slow = slow->right;
        fast = fast->right->right;
    }
    return slow;
}

Node *SortedDLLToBST(Node* head)
{
    if(head==nullptr || head->right==nullptr)
        return head;
        
    Node* mid = getMid(head);
    Node* bck = mid->left;
    Node* fwd = mid->right;
    
    mid->left = nullptr;
    if(bck!=nullptr) bck->right = nullptr;
    
    mid->right = nullptr;
    if(fwd!=nullptr) fwd->left = nullptr;
    
    mid->left = SortedDLLToBST(bck==nullptr ? nullptr : head);
    mid->right = SortedDLLToBST(fwd);
    return mid;
}

// input_Section_====================================================================

void display(Node *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

Node* makeList(int n) {
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        while (n-- > 0) {
            int val; cin >> val;
            Node* node = new Node(val);
            prev->right = node;
            node->left = prev;
            prev = prev->right;
        }

        Node* head = dummy->right;
        head->left = dummy->right = nullptr;

        return head;
    }

void solve()
{
    int n;
    cin >> n;
    Node* head = makeList(n);
    
    head = SortedDLLToBST(head);
    display(head);
}

int main()
{
    solve();
    return 0;
}