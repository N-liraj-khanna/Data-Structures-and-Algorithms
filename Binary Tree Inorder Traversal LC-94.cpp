// morris traversal
// tc=O(n)
// sc=o(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        TreeNode* curr=root;
        TreeNode* prev;
        while(curr){
            if(curr->left){
                prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==curr){
                    res.push_back(curr->val);
                    prev->right=NULL;
                    curr=curr->right;
                }else{
                    prev->right=curr;
                    curr=curr->left;
                }
            }else{
                res.push_back(curr->val);
                curr=curr->right;
            }
        }        
        return res;
    }
};

// tc=O(n)
// sc=o(h)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        
        stack<TreeNode*> stk;
        stk.push(root);
        root=root->left;

        while(true){
            if(root){
                stk.push(root);
                root=root->left;
            }else{
                if(stk.empty()) break;
                TreeNode* node = stk.top();
                stk.pop();
                res.push_back(node->val);
                root=node->right;
            }
        }
        return res;
    }
};



// tc=O(n)
// sc=o(h)
class Solution {
public:
    vector<int> res;
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->left);
        res.push_back(root->val);
        solve(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        return res;
    }
};

class Solution {
public:
    vector<int> solve(TreeNode* root,vector<int> &res){
        if(!root) return res;
        solve(root->left, res);
        res.push_back(root->val);
        solve(root->right, res);
        return res;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        solve(root, res);
        return res;
    }
};