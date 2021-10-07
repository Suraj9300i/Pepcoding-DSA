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

class Node{
    public:
    int row,col;
    TreeNode* treeNode;
    Node(){}
    Node(int _row,int _col,TreeNode* tn){
        row = _row;
        col = _col;
        treeNode = tn;
    }
};

int left_width = INT_MAX;
int right_width = INT_MIN;
void calcWidth(TreeNode* root,int state){
    if(root==nullptr) return;
    left_width = min(left_width,state);
    right_width = max(right_width,state);
    calcWidth(root->left,state-1);
    calcWidth(root->right,state+1);
}

bool operator<(const Node& n1, const Node& n2){
    if(n1.col!=n2.col)
        return n1.col<n2.col;
    if(n1.row!=n2.row)
        return n1.row<n2.row;
    return n1.treeNode->val < n2.treeNode->val;
}

vector<vector<int>> verticalOrderTraversal(TreeNode* root) {
    left_width = INT_MAX;
    right_width = INT_MIN;
    calcWidth(root,0);
    int w = right_width-left_width+1;
    vector<vector<int>> ans(w,vector<int>());
    priority_queue<Node> pq;
    pq.push(Node(0,-left_width,root));
    while(!pq.empty()){
        int row = pq.top().row;
        int col = pq.top().col;
        TreeNode* treeNode = pq.top().treeNode;
        pq.pop();
        
        ans[col].push_back(treeNode->val);
        if(treeNode->left!=nullptr) pq.push(Node(row+1,col-1,treeNode->left));
        if(treeNode->right!=nullptr) pq.push(Node(row+1,col+1,treeNode->right));
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