/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,int &res, int maxi){
        if(!root) return;
        if(root->val>=maxi) res++;
        dfs(root->left, res, max(maxi, root->val));
        dfs(root->right, res, max(maxi, root->val));
    }
    int goodNodes(TreeNode* root) {
        int res=1;
        dfs(root->left, res, root->val);
        dfs(root->right, res, root->val);
        return res;
    }
};