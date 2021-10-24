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

vector<vector<int>> res;
void solver(TreeNode* root,vector<int> &path){
    if(root==nullptr) return;
    if(root->left==nullptr && root->right==nullptr){
        path.push_back(root->val);
        
        vector<int>copy;
        
        for(int ele:path)  {
            cout<<ele<<" ";
        }
        cout<<endl;
    
        res.push_back(copy);
        
        path.pop_back();
        return;
    }
    
    path.push_back(root->val);
    solver(root->left,path);
    solver(root->right,path);
    path.pop_back();
}

vector<vector<int>> rootToAllLeafPath(TreeNode* root)
{
    vector<int> path;
    solver(root,path);

    return res;
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

  vector<vector<int>> ans = rootToAllLeafPath(root);
  if (ans.size() == 0)
    cout << endl;
  for (auto& al : ans)
  {
    for (int ele : al)
      cout << (ele + " ");
    cout << endl;
  }
}

int main()
{
  solve();
  return 0;
}