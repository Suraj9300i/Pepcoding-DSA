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

TreeNode* solve(vector<int> &preorder, vector<int> &inorder,int prs,int pre,int ins,int ine){
    if(prs>pre || ins>ine)
        return nullptr;
    TreeNode* node = new TreeNode(preorder[prs]);
    int k = -1;
    for(int i=ins;i<=ine;i++){
        if(inorder[i]==node->val){
            k = i;
            break;
        }
    }
    int clt = k-ins;
    node->left = solve(preorder,inorder,prs+1,prs+clt,ins,k-1);
    node->right = solve(preorder,inorder,prs+clt+1,pre,k+1,ine);
    return node;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return solve(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
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

    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = buildTree(pre, in);
    display(root);
}

int main()
{
    solve();
    return 0;
}