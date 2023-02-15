// tc=o(1)
// sc=o(1)
class Solution {
public:
    bool checkTree(TreeNode* root) {
        return root->val==root->left->val+root->right->val;
    }
};