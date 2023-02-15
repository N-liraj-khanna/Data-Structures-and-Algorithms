// tc=o(n)
// sc=o(n)
class Solution {
public:
    bool solve(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;
        if(!left || !right) return false;
        
        if(left->val!=right->val) return false;
        
        if(!solve(left->left,right->right) || !solve(left->right,right->left)) return false;
        
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return solve(root->left, root->right);
    }
};