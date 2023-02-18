// tc=o(n)
// tc=o(h)
class BSTIterator {
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        while(root){
            stk.push(root);
            root=root->left;
        }
    }
    
    int next() {
        int op=stk.top()->val;
        TreeNode* node=stk.top()->right;
        stk.pop();
        while(node){
            stk.push(node); 
            node=node->left;
        }
        
        return op;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};

// tc=o(n)
// tc=o(n)
class BSTIterator {
public:
    stack<int> stk;
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->right);
        stk.push(root->val);
        solve(root->left);
    }
    BSTIterator(TreeNode* root) {
        solve(root);
    }
    
    int next() {
        if(stk.empty()) return -1;
        int t=stk.top();
        stk.pop();
        return t;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};