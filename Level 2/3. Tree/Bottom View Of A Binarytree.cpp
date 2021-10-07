#include <iostream>
#include <vector>
#include <climits>
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
void calcWidth(TreeNode* root,int state){
    if(root==nullptr) return;
    mn = min(mn,state);
    mx = max(mx,state);
    calcWidth(root->left,state-1);
    calcWidth(root->right,state+1);
}

vector<int> BottomView(TreeNode *root)
{
    mn = INT_MAX;
    mx = INT_MIN;
    calcWidth(root,0);
    int w = mx-mn+1;
    
    vector<int> btView(w);
    queue<pair<TreeNode*,int>> qu;
    qu.push({root,-mn});
    while(!qu.empty()){
        TreeNode* node = qu.front().first;
        int state = qu.front().second;
        qu.pop();
        btView[state] = node->val;
        if(node->left!=nullptr) qu.push({node->left,state-1});
        if(node->right!=nullptr) qu.push({node->right,state+1});
    }
    return btView;
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

    vector<int> ans = BottomView(root);

    for (int i : ans)
    {
        cout << i << " ";
    }
}

int main()
{
    solve();
    return 0;
}