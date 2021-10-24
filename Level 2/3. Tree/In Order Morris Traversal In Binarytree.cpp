#include <iostream>
#include <vector>
#include <queue>
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

TreeNode* rightMostNode(TreeNode* node,TreeNode* cur){
    while(node->right!=nullptr && node->right!=cur){
        node = node->right;
    }
    return node;
}

vector<int> morrisInTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* cur = root;
    while(cur!=nullptr){
        TreeNode* lc = cur->left;
        if(lc==nullptr){
            ans.push_back(cur->val);
            cur = cur->right;
        }
        else{
            TreeNode* rmn = rightMostNode(lc,cur);
            if(rmn->right==nullptr){
                rmn->right = cur;
                cur = lc;
            }
            else if(rmn->right==cur){
                ans.push_back(cur->val);
                rmn->right = nullptr;
                cur = cur->right;
            }
        }
    }
    return ans;
}

// input_section=================================================

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

  vector<int> IDX(1, 0);
  TreeNode* root = createTree(arr, IDX);

  vector<int> ans = morrisInTraversal(root);

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