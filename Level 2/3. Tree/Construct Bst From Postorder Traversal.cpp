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
TreeNode* solve(vector<int> &postorder,int mn,int mx){
    if(cur<0 || postorder[cur]<mn || postorder[cur]>mx)
        return nullptr;
    TreeNode* nn = new TreeNode(postorder[cur]);
    cur--;
    nn->right = solve(postorder,nn->val,mx);
    nn->left = solve(postorder,mn,nn->val-1);
    return nn;
}

TreeNode *bstFromPostorder(vector<int> &postorder)
{
    cur = postorder.size()-1;
    return solve(postorder,INT_MIN,INT_MAX);
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
    vector<int> post(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }

    TreeNode *root = bstFromPostorder(post);
    display(root);
}

int main()
{
    solve();
    return 0;
}