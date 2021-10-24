class Solution {
    // node_to_leaf && leaf_to_leaf
    pair<int,int> solve(Node* root){
        if(root==nullptr) return {INT_MIN,INT_MIN};
        if(root->left==nullptr && root->right==nullptr)
            return {root->data,INT_MIN};
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        int nc = INT_MIN;
        if(root->left!=nullptr && root->right!=nullptr){
            nc = left.first+right.first+root->data;
        }
        
        pair<int,int> ans;
        ans.first = max(left.first,right.first)+root->data;
        ans.second = max({left.second,right.second,nc});
        return ans;
    }
    public:
    int maxPathSum(Node* root)
    {
        pair<int,int> ans = solve(root);
        if(root->left!=nullptr && root->right==nullptr){
            return max(ans.first,ans.second);
        }
        if(root->left==nullptr && root->right!=nullptr){
            return max(ans.first,ans.second);
        }
        return ans.second;
    }
}