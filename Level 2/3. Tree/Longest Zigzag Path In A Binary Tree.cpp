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

int res = 0;
pair<int,int> solver(TreeNode* root){
    if(root==nullptr) return {-1,-1};
    pair<int,int> left = solver(root->left);
    pair<int,int> right = solver(root->right);
    
    pair<int,int> ans = {0,0};
    ans.first = 1+left.second;
    ans.second = 1+right.first;
    
    res = max(res,ans.first);
    res = max(res,ans.second);
    
    return ans;
}

int longestZigZagPath(TreeNode *root)
{
    solver(root);
    return res;
}

// input_Section_====================================================================

TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{
    if (IDX[0] > arr.size() || arr[IDX[0]] == -1){
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

    cout << longestZigZagPath(root) << endl;
}

int main()
{
    solve();
    return 0;
}