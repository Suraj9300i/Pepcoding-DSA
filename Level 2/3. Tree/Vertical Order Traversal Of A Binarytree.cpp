#include <iostream>
#include <vector>
#include <climits>
#include <map>
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

int mn = INT_MAX;
int mx = INT_MIN;
void helper(TreeNode* root,int vl){
    if(root==nullptr) return;
    mn = min(mn,vl);
    mx = max(mx,vl);
    helper(root->left,vl-1);
    helper(root->right,vl+1);
}

vector<vector<int>> verticalOrderTraversal(TreeNode *root)
{
    mn = INT_MAX;
    mx = INT_MIN;
    helper(root,0);
    int width = mx-mn+1;
    vector<vector<int>> ans(width,vector<int>());
    queue<pair<TreeNode*,int>> qu;
    qu.push({root,-mn});
    while(!qu.empty()){
        pair<TreeNode*,int> cur = qu.front();
        TreeNode* node = cur.first;
        int vl = cur.second;
        qu.pop();
        ans[vl].push_back(node->val);
        if(node->left!=nullptr) qu.push({node->left,vl-1});
        if(node->right!=nullptr) qu.push({node->right,vl+1});
    }
    return ans;
}

// Using map
// vector<vector<int>> verticalOrderTraversal(TreeNode *root)
// {
//     vector<vector<int>> ans;
//     map<int,vector<int>> mp;
//     queue<pair<TreeNode*,int>> qu;
//     qu.push({root,0});
//     while(!qu.empty()){
//         pair<TreeNode*,int> cur = qu.front();
//         mp[cur.second].push_back(cur.first->val);
//         qu.pop();
//         if(cur.first->left!=nullptr) 
//             qu.push({cur.first->left,cur.second-1});
//         if(cur.first->right!=nullptr) 
//             qu.push({cur.first->right,cur.second+1});
//     }
//     for(auto it:mp){
//         ans.push_back(it.second);
//     }
//     return ans;
// }

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

    vector<vector<int>> ans = verticalOrderTraversal(root);
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