// tc=O(n)
// sc=o(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            res.push_back(node->val);
            stk.pop();
            if(node->right){
                stk.push(node->right);
            }if(node->left){
                stk.push(node->left);
            }
        }
        return res;
    }
};
// tc=O(n)
// sc=o(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> stk;
        while(true){
            if(root){
                res.push_back(root->val);
                stk.push(root);
                root=root->left;
            }else{
                if(stk.empty()) break;
                TreeNode* temp=stk.top();
                stk.pop();
                root=temp->right;
            }
        }
        return res;
    }
};
// tc=O(n)
// sc=o(h)
class Solution {
public:
    vector<int> solve(TreeNode* root, vector<int>& res){
        if(!root) return res;
        res.push_back(root->val);
        solve(root->left, res);
        solve(root->right, res);
        return res;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        solve(root,res);
        return res;
    }
};