// tc=o(n)
// tc=o(n)

class Solution {
public:
    int solve(TreeNode* root, int& maxi){
        if(!root) return 0;
        
        int lh=solve(root->left,maxi);
        int rh=solve(root->right,maxi);
        
        maxi=max(lh+rh,maxi);

        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        solve(root,maxi);
        return maxi;
    }
};

// tc=o(n*n)
// tc=o(n)
class Solution {
public:
    int height(TreeNode* root, int lvl){
        if(!root) return lvl;
        lvl=max(height(root->left,lvl+1),height(root->right,lvl+1));
        return lvl;
    }
    int solve(TreeNode* root, int maxi){
        if(!root) return maxi;
        int lh=height(root->left,0);
        int rh=height(root->right,0);
        maxi=max(maxi,lh+rh);
        
        maxi=solve(root->left, maxi);
        maxi=solve(root->right, maxi);

        return maxi;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root,0);
    }
};