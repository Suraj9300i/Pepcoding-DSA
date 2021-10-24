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

pair<int,int> solver(TreeNode* root){
    if(root==nullptr) return {0,0};
    pair<int,int> left = solver(root->left);
    pair<int,int> right = solver(root->right);
    
    pair<int,int> ans;
    ans.first = root->val + left.second + right.second;
    ans.second = 0;
    ans.second = max(ans.second , left.first+right.first);
    ans.second = max(ans.second , left.first+right.second);
    ans.second = max(ans.second , left.second+right.first);
    ans.second = max(ans.second , left.second+right.second);
    return ans;
}

int HouseRobber(TreeNode *root)
{
    pair<int,int> ans = solver(root);
    return max(ans.first,ans.second);
}

// input_Section_====================================================================

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
    cout << HouseRobber(root) << endl;
}

int main()
{
    solve();
    return 0;
}