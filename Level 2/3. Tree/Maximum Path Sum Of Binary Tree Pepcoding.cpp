#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class TreeNode
{
public:
  int val = 0;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;

  TreeNode(int val)
  {
    this->val = val;
  }
};

// Node-to-Node , Root-to-Node
pair<int,int> solver(TreeNode* root){
    if(root==nullptr) return {INT_MIN,INT_MIN};
    if(root->left==nullptr && root->right==nullptr){
        return {root->val,root->val};
    }
    pair<int,int> left = solver(root->left);
    pair<int,int> right = solver(root->right);
    
    pair<int,int> ans;
    ans.second = max(root->val,max(left.second,right.second)+root->val);
    
    ans.first = max(left.first, right.first);
    ans.first = max(ans.first,ans.second);
    if(root->left && root->right){
        int cand = left.second + right.second + root->val;
        ans.first = max(ans.first,cand);
    }
    return ans;
}

int maxPathSum(TreeNode* root)
{
  pair<int,int> ans = solver(root);
  return max(ans.first,ans.second);
}

// input_Section=================================================

TreeNode* createTree(vector<int>& arr, vector<int>& IDX)
{
  if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
  {
    IDX[0]++;
    return nullptr;
  }
  TreeNode* node = new TreeNode(arr[IDX[0]++]);
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
  int tar;
  cin >> tar;
  vector<int> IDX(1, 0);
  TreeNode* root = createTree(arr, IDX);
  cout << maxPathSum(root) << endl;
}

int main()
{
  solve();
  return 0;
}