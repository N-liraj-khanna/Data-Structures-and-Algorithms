// tc=o(n)
// sc=o(h)
class Solution {
public:
    int solve(TreeNode* root, int lvl){
        if(!root) return lvl;
        return max(solve(root->left,lvl+1),solve(root->right, lvl+1));
    }
    int maxDepth(TreeNode* root) {
        return solve(root,0);
    }
};