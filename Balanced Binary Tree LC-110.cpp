// tc=o(n)
// tc=o(n)
class Solution {
public:
    int solve(TreeNode* root){
        if(!root) return 0;
        
        int lh=solve(root->left);
        int rh=solve(root->right);
        
        if(lh==-1 || rh==-1) return -1;
        
        if(abs(lh-rh)>1) return -1;

        return max(lh,rh)+1;
    }

    bool isBalanced(TreeNode* root) {
        return solve(root)!=-1;
    }
};

// tc=o(n*n)
// tc=o(n)
class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        return max(height(root->left),height(root->right))+1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int lh=height(root->left);
        int rh=height(root->right);
        
        if(abs(lh-rh)>1) return false;
        
        if(!isBalanced(root->left)|| !isBalanced(root->right)){
            return false;
        }
        return true;
    }
};