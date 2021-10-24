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
int pr = INT_MIN;
bool isValidBST(TreeNode *root)
{
    if(root==nullptr)
        return true;
    if(!isValidBST(root->left))
        return false;
    
    if(root->val < pr)
        return false;
    pr = root->val;
    
    if(!isValidBST(root->right))
        return false;
    return true;
}

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
    cout << (boolalpha) << isValidBST(root);
}

int main()
{
    solve();
    return 0;
}