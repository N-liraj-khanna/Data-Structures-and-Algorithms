// tc=o(n)
// sc=o(n)
bool helper(TreeNode* root, int t, vector<int>& res){
    if(!root) return false;

    res.push_back(root->val);

    if(root->val==t) return true; 
    if (helper(root->left,t,res) || helper(root->right,t,res)) return true;
    res.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    helper(A,B,res);
    return res;
}
