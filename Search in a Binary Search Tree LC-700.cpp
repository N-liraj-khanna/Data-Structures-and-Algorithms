// dfs
// tc=o(logn)
// sc=o(logn)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(root->val==val) return root;
            else if(root->val>val) root=root->left;
            else root=root->right;
        }
        return NULL;
    }
};

// dfs
// tc=o(logn)
// sc=o(logn)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(root->val==val) return root;
        else if(root->val>val)   
            return searchBST(root->left,val);
        else
            return searchBST(root->right,val);
        
    }
};