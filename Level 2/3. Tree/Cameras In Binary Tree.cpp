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

int ans = 0;
int solve(TreeNode* root){
    if(root==nullptr) return 0;
    int left = solve(root->left);
    int right = solve(root->right);
    
    if(left==-1 || right==-1){
        ans++;
        return 1;
    }
    else if(left==1 || right==1){
        return 0;
    }
    else{
        return -1;
    }
}

int MinCamerasInBT(TreeNode *root)
{
    ans = 0;
    if(solve(root)==-1)
        ans++;
    return ans;
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
    cout << MinCamerasInBT(root) << endl;
}

int main()
{
    solve();
    return 0;
}