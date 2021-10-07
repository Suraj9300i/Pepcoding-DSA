#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};

TreeNode* solve(vector<int> &in,int low,int high){
    if(low>high) return nullptr;
    int mid = (high+low)/2;
    TreeNode* nn = new TreeNode(in[mid]);
    nn->left = solve(in,low,mid-1);
    nn->right = solve(in,mid+1,high);
    return nn;
}

TreeNode *constructFromInOrder(vector<int> &in)
{
    return solve(in,0,in.size()-1);
}

// input_Section_====================================================================

void display(TreeNode *node)
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

void solve()
{
    int n;
    cin >> n;
    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = constructFromInOrder(in);
    display(root);
}

int main()
{
    solve();
    return 0;
}