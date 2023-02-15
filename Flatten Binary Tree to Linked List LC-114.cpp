// tc=o(N+N)
// sc=o(N)

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        
        flatten(root->left);
        flatten(root->right);

        if(root->left){
            TreeNode* temp=root->right;
            root->right=root->left;
            root->left=NULL;
            while(root->right) root=root->right;
            root->right=temp;
        }
    }
};
// tc=o(N+N+N)
// sc=o(N+N)
class Solution {
public:
    void solve(TreeNode* root, map<int,TreeNode*>& mp, int& i){
        if(!root) return;
        mp[++i]=root;
        solve(root->left,mp,i);
        solve(root->right,mp,i);
    }
    void flatten(TreeNode* root) {
        map<int,TreeNode*> mp;
        int i=0;
        solve(root,mp,i);
        TreeNode* node=root;
        for(auto i: mp){
            i.second->left=NULL;
            i.second->right=NULL;
        }
        for(auto i: mp){
            if(i.first!=1){
                node->right=i.second;
                node->left=NULL;
                node=node->right;
            }
        }
    }
};