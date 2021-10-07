#include <iostream>
#include <vector>
#include <queue>
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

int mn = INT_MAX;
int mx = INT_MIN;
void helper(TreeNode* root,int level){
    if(root==nullptr) return;
    mn = min(mn,level);
    mx = max(mx,level);
    helper(root->left,level-1);
    helper(root->right,level+1);
}

int width(TreeNode *root)
{
    mn = INT_MAX;
    mx = INT_MIN;
    helper(root,0);
    return mx-mn+1;
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

    cout << width(root) << endl;
}

int main()
{
    solve();
    return 0;
}