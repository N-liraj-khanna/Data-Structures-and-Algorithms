// tc=o(n)
// sc=o(n)
class Solution {
public:
    int solve(TreeNode* root, int& maxi){
        if(!root) return 0;

        int lh=max(0,solve(root->left,maxi));
        int rh=max(0,solve(root->right,maxi));
        
        maxi=max(root->val+lh+rh,maxi);
        
        return root->val+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};