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

int getInorderIndex(vector<int> &inorder,int ele){
    for(int i=0;i<inorder.size();i++){
        if(ele==inorder[i])
            return i;
    }
    return -1;
}

TreeNode* buildTree(vector<int> &inorder, vector<int> levelorder)
{
    if(levelorder.size()==0)
        return nullptr;
    if(levelorder.size()==1)
        return new TreeNode(levelorder[0]);
    TreeNode* node = new TreeNode(levelorder[0]);
    int k = getInorderIndex(inorder,levelorder[0]);
    vector<int> left,right;
    for(int i=1;i<levelorder.size();i++){
        int ind = getInorderIndex(inorder,levelorder[i]);
        if(ind<=k) left.push_back(levelorder[i]);
        else right.push_back(levelorder[i]);
    }
    node->left = buildTree(inorder,left);
    node->right = buildTree(inorder,right);
    return node;
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

    vector<int> level(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> level[i];
    }

    TreeNode *root = buildTree(post,level);
    display(root);
}

int main()
{
    solve();
    return 0;
}