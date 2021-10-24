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

int left_width = 0;
int right_width = 0;
void calc_width(TreeNode* root,int width){
    if(root==nullptr) return;
    left_width = min(left_width,width);
    right_width = max(right_width,width);
    calc_width(root->left,width-1);
    calc_width(root->right,width+1);
}

void solver(TreeNode* root,vector<int> &ans,int w){
    if(root==nullptr) return;
    ans[w] += root->val;
    solver(root->left,ans,w-1);
    solver(root->right,ans,w+1);
}

vector<int> verticalOrderSum(TreeNode *root)
{
    left_width = 0;
    right_width = 0;
    calc_width(root,0);
    vector<int> ans(right_width-left_width+1,0);
    solver(root,ans,-left_width);
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

    vector<int> ans = verticalOrderSum(root);
    for (int j : ans)
    {
        cout << j << "";
    }
}

int main()
{
    solve();
    return 0;
}