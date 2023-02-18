// tc=o(n)
// sc=o(n)

class Solution {
public:
    bool solve(TreeNode* root,int k, int& node,int& res){
        if(!root || res!=-1) return false;
        
        if(solve(root->left,k, node,res)) return true;

        node++;
        
        if(node==k){
            res=root->val;
            return true;
        };
        
        if(solve(root->right,k, node,res)) return true;

        return false;
    }
    int kthSmallest(TreeNode* root, int k) {
        int res=-1;
        int node=0;
        solve(root,k,node,res);
        return res;
    }
};

// tc=o(n)
// sc=o(n)
class Solution {
public:

    int kthSmallest(TreeNode* root, int& k) {
        if(!root) return -1;

        int l = kthSmallest(root->left,k);
        if(l!=-1) return l;
        k--;
        if(k==0) return root->val;

        int r=kthSmallest(root->right,k);
        return r;
    }
};