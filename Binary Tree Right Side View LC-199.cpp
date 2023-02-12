// tc=o(n)
// sc=o(h)
class Solution {
public:
    void solve(TreeNode* root, int lvl, vector<int>& res){
        if(!root) return;
        
        if(res.size()==lvl)
            res.push_back(root->val);

        solve(root->right,lvl+1,res);
        solve(root->left,lvl+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        solve(root,0,res);
        return res;
    }
};