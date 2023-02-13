  // tc=o(n)
  // sc=o(n)
  class Solution {
public:
    bool hasPathSum(TreeNode* root, int t) {
        if(!root) return false;
        if(root->val==t && !root->left && !root->right) return true;

        if(hasPathSum(root->left,t-root->val) || hasPathSum(root->right,t-root->val)) 
            return true;
            
        return false;
    }
};