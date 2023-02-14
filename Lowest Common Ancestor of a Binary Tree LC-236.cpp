
// tc=o(n)
// sc=o(n)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;
        
        TreeNode* left=lowestCommonAncestor(root->left, p, q);
        TreeNode* right=lowestCommonAncestor(root->right, p, q);

        if(!left) return right;
        if(!right) return left;
        
        return root;
    }
};

// tc=o(n+n+n)
// sc=o(n+n)
class Solution {
public:
    bool solve(TreeNode* root, TreeNode* node, vector<TreeNode*>& vec){
        if(!root) return false;
        vec.push_back(root);
        if(node==root) return true;
        if(solve(root->left,node,vec) || solve(root->right,node,vec)) return true;
        vec.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1;
        solve(root,p,v1);
        vector<TreeNode*> v2;
        solve(root,q,v2);

        for(int i=1;i<min(v1.size(),v2.size());i++){
            if(v1[i]!=v2[i]) return v1[i-1];
        }
        return v1.size()<v2.size()?p:q;
    }
};