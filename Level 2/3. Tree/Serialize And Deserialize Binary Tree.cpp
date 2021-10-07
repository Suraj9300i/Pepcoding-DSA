#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    if(root==nullptr)
        return "?";
    string ls = serialize(root->left);
    string rs = serialize(root->right);
    return to_string(root->val)+" "+ls+" "+rs+" ";
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string s)
{
    vector<int> v;
    string str = "";
    for(char ch:s){
        if(ch==' '){
            if(str=="") continue;
            if(str=="?") v.push_back(-1e8);
            else v.push_back(stoi(str));
            str = "";
        }
        else str.push_back(ch);
    }
    TreeNode* root = new TreeNode(v[0]);
    stack<pair<TreeNode*,int>> st;
    st.push({root,1});
    for(int i=1;i<v.size();i++){
        if(v[i]==-1e8){
            st.top().second++;
            if(st.top().second>2){
                st.pop();
            }
        }
        else{
            TreeNode* node = new TreeNode(v[i]);
            if(st.top().second==1){
                st.top().first->left = node;
                st.top().second++;
            }
            else{
                st.top().first->right = node;
                st.pop();
            }
            st.push({node,1});
        }
    }
    return root;
}

// input_Section_====================================================================

void display(TreeNode *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

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
    string s = serialize(root);
    display(deserialize(s));
}

int main()
{
    solve();
    return 0;
}