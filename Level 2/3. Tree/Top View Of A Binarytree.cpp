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

int left_width = INT_MAX;
int right_width = INT_MIN;
void width(TreeNode* root,int state){
    if(root==nullptr) return;
    left_width = min(left_width,state);
    right_width = max(right_width,state);
    width(root->left,state-1);
    width(root->right,state+1);
}

vector<int> TopView(TreeNode *root)
{
    left_width = INT_MAX;
    right_width = INT_MIN;
    width(root,0);
    int w = right_width-left_width+1;
    vector<int> topView(w,-1);
    queue<pair<TreeNode*,int>> qu;
    qu.push({root,-left_width});
    while(!qu.empty()){
        TreeNode* node = qu.front().first;
        int state = qu.front().second;
        qu.pop();
        if(topView[state]==-1){
            topView[state] = node->val;
        }
        if(node->left!=nullptr) qu.push({node->left,state-1});
        if(node->right!=nullptr) qu.push({node->right,state+1});
    }
    return topView;
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

    vector<int> ans = TopView(root);

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