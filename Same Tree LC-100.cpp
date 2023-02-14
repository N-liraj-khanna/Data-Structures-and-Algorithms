// tc=o(n)
// sc=o(n)

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q || p->val!=q->val) return false;

        if(!isSameTree(p->left,q->left) || !isSameTree(p->right,q->right)){
            return false;
        }
        return true;
    }
};

// tc=o(n+m)
// sc=o(n+m)
class Solution {
public:
    void solve(TreeNode* node,string& res){
        if(!node){
            res+=" ";
            return;
        }
        res+=char(node->val);
        solve(node->left,res);
        solve(node->right,res);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string a;
        solve(p,a);
        string b;
        solve(q,b);
        return a==b;
    }
};