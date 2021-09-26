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

TreeNode* solve(vector<int> &inorder, vector<int> &postorder,int ps,int pe,int is,int ie){
    if(is>ie || ps>pe)
        return nullptr;
    TreeNode* node = new TreeNode(postorder[pe]);
    int k = -1;
    for(int i=is;i<=ie;i++){
        if(inorder[i]==node->val){
            k = i;
            break;
        }
    }
    int clt = k-is;
    int crt = ie-k;
    node->left = solve(inorder,postorder,ps,ps+clt-1,is,k-1);
    node->right = solve(inorder,postorder,ps+clt,pe-1,k+1,ie);
    return node;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    return solve(inorder,postorder,0,postorder.size()-1,0,inorder.size());
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

    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = buildTree(in, post);
    display(root);
}

int main()
{
    solve();
    return 0;
}