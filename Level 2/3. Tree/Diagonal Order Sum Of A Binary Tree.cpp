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

void solver(TreeNode* root,vector<int> &ans,int w){
    if(root==nullptr) return;
    
    if(w<ans.size()) ans[w] += root->val;
    else ans.push_back(root->val);
    
    solver(root->left,ans,w+1);
    solver(root->right,ans,w);
}

vector<int> DiagonalOrderSum(TreeNode *root)
{
    vector<int> ans;
    solver(root,ans,0);
    return ans;
}

// input_section=================================================

TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{

    if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
    {
        IDX[0]++;
        return nullptr;
    }

    TreeNode *node = new TreeNode(arr[IDX[0]++]);
    node->left = createTree(arr, IDX);
    node->right = createTree(arr, IDX);

    return node;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> IDX(1, 0);
    TreeNode *root = createTree(arr, IDX);

    vector<int> ans = DiagonalOrderSum(root);
    for (int j : ans)
    {
        cout << j << " ";
    }
}

int main()
{
    solve();
    return 0;
}