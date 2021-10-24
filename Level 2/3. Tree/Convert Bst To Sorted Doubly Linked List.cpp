#include<iostream>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val){
        val = _val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* head = nullptr;
TreeNode* pre = nullptr;
void solve(TreeNode* root){
    if(root==nullptr) return;
    solve(root->left);
    
    root->left = pre;
    if(pre!=nullptr)
        pre->right = root;
    else
        head = root;
    pre = root;
    
    solve(root->right);
}

TreeNode* BSTtoDLL(TreeNode* root){
    head = nullptr;
    pre = nullptr;
    solve(root);
    pre->right = head;
    head->left = pre;
    return head;
}

void display(TreeNode* node) {
    TreeNode* head = node;
    while (node != nullptr) {
      cout<<(node->val)<<" ";
      node = node->right;
      if (node == head)
        break;
    }
}

TreeNode* constructBST(int arr[],int start,int end){
    if(start>end) return nullptr;
    int mid = start+(end-start)/2;
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = constructBST(arr,start,mid-1);
    root->right = constructBST(arr,mid+1,end);
    return root;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    TreeNode* root = constructBST(arr,0,n-1);
    root = BSTtoDLL(root);
    display(root);
    
    return 0;
}