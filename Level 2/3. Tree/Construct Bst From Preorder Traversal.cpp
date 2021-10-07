#include <iostream>
#include <vector>
#include <climits>
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

int cur;
TreeNode* solve(vector<int> &preorder,int mn,int mx){
    if(cur>=preorder.size() || preorder[cur]<mn || preorder[cur]>mx)
        return nullptr;
    TreeNode* nn = new TreeNode(preorder[cur]);
    cur++;
    nn->left = solve(preorder,mn,nn->val);
    nn->right = solve(preorder,nn->val+1,mx);
    return nn;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    cur = 0;
    return solve(preorder,INT_MIN,INT_MAX);
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
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    TreeNode *root = bstFromPreorder(pre);
    display(root);
}

int main()
{
    solve();
    return 0;
}