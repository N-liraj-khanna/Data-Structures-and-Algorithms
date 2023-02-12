// tc=O(n)
// sc=O(n)

class Solution {
public:
    vector<int> solve(TreeNode* root, vector<int>& res){
        if(!root) return res;
        solve(root->left, res);
        solve(root->right, res);
        res.push_back(root->val);
        return res;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        solve(root,res);
        return res;
    }
};
// tc=O(n)
// sc=O(2n)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> stk1;
        stack<int> stk2;
        stk1.push(root);

        while(!stk1.empty()){
            TreeNode* node = stk1.top();
            stk1.pop();
            stk2.push(node->val);
            if(node->left){
                stk1.push(node->left);
            }
            if(node->right){
                stk1.push(node->right);
            }
        }
        while(!stk2.empty()){
            res.push_back(stk2.top());
            stk2.pop();
        } 
        return res;
    }
};