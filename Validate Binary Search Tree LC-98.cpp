// tc=o(n)
// sc=o(n)
class Solution {
public:
    bool solve(TreeNode* root, long mini, long maxi){
        if(!root) return true;
        if(mini>=root->val || root->val>=maxi) return false;
        
        if(!solve(root->left,mini,root->val) || !solve(root->right,root->val,maxi)) return false;

        return true;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MIN,LONG_MAX);
    }
};