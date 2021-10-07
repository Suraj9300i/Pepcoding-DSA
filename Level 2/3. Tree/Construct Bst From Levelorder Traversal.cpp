#include <iostream>
#include <vector>
#include <queue>
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

class levelPair
{
public:
    TreeNode *par = nullptr;
    int lb = -(int)1e8;
    int rb = (int)1e8;

    levelPair()
    {
    }

    levelPair(TreeNode *par, int lb, int rb)
    {
        this->par = par;
        this->lb = lb;
        this->rb = rb;
    }
};

TreeNode* solve(vector<int> v){
    if(v.size()==0) return nullptr;
    TreeNode* nn = new TreeNode(v[0]);
    vector<int> left,right;
    for(int i=1;i<v.size();i++){
        if(v[i]<v[0]) left.push_back(v[i]);
        else right.push_back(v[i]);
    }
    nn->left = solve(left);
    nn->right = solve(right);
    return nn;
}

TreeNode *constructBSTFromLevelOrder(vector<int> &arr)
{
    return solve(arr);
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

    TreeNode *root = constructBSTFromLevelOrder(pre);
    display(root);
}

int main()
{
    solve();
    return 0;
}