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

int width(TreeNode* root,int state){
    if(root==nullptr) return state;
    int x = width(root->left,state+1);
    int y = width(root->right,state);
    return max(x,y);
}

vector<vector<int>> diagonalOrder(TreeNode *root)
{
    int w = width(root,0);
    vector<vector<int>> ans(w,vector<int>());
    queue<pair<TreeNode*,int>> qu;
    qu.push({root,0});
    while(!qu.empty()){
        TreeNode* node = qu.front().first;
        int state = qu.front().second;
        qu.pop();
        
        ans[state].push_back(node->val);
        
        if(node->left!=nullptr)
            qu.push({node->left,state+1});
        if(node->right!=nullptr)
            qu.push({node->right,state});
    }
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

    vector<vector<int>> ans = diagonalOrder(root);
    int idx = 0;
    for (vector<int> &i : ans)
    {
        cout << idx++ << " -> ";
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}