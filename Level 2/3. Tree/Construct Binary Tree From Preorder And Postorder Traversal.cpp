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

TreeNode* helper(vector<int> &pre, vector<int> &post,int prs,int pree,int pos,int poe){
    if(prs>pree || pos>poe) return nullptr;
    if(prs==pree) return new TreeNode(pre[prs]);
    TreeNode* node = new TreeNode(pre[prs]);
    int k = -1;
    for(int i=pos;i<=poe;i++){
        if(pre[prs+1]==post[i]){
            k = i;
            break;
        }
    }
    int cls = k-pos+1;
    node->left = helper(pre,post,prs+1,prs+cls,pos,k);
    node->right = helper(pre,post,prs+cls+1,pree,k+1,poe-1);
    return node;
}

TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
{
    return helper(pre,post,0,pre.size()-1,0,post.size()-1);
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

    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    TreeNode *root = constructFromPrePost(pre, post);
    display(root);
}

int main()
{
    solve();
    return 0;
}