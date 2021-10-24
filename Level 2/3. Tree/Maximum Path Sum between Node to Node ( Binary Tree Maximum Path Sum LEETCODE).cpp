class Solution {
    //  node_to_node && root_to_node
        pair<int,int> solve(TreeNode* root){
            if(root==nullptr) return {INT_MIN,INT_MIN};
            if(root->left==nullptr && root->right==nullptr) 
                return {root->val,root->val};
            
            pair<int,int> left = solve(root->left);
            pair<int,int> right = solve(root->right);
            
            pair<int,int> ans;
            ans.second = max(left.second,right.second)+root->val;
            ans.second = max(ans.second,root->val);
            
            ans.first = max({left.first,right.first,ans.second});
            if(root->left!=nullptr && root->right!=nullptr){
                ans.first = max(ans.first, left.second+right.second+root->val);
            }
            
            return ans;
        }
public:
    int maxPathSum(TreeNode* root) {
        pair<int,int> ans = solve(root);
        return max(ans.first,ans.second);
    }
};