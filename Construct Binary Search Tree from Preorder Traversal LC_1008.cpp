// tc=o(n)
// sc=o(n)
class Solution {
public:
    TreeNode* solve(vector<int>& pre, int& idx,int mini, int maxi){
        if(idx==pre.size()) return NULL;
        TreeNode* root;
        if(mini<pre[idx] && pre[idx]<maxi){
            root=new TreeNode(pre[idx]);
            idx++;
            root->left=solve(pre,idx,mini,root->val);
            root->right=solve(pre,idx,root->val,maxi);
        }else{
            root=NULL;
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return solve(preorder, idx, INT_MIN, INT_MAX);
    }
};


// tc=o(n+nlogn)
// sc=o(n)
class Solution {
public:
    TreeNode* solve(int start, int end, int& idx, vector<int>& preorder, vector<int>& inorder){
        if(start>end) return NULL;
        if(idx<preorder.size()){
            TreeNode* node=new TreeNode(preorder[idx]);
            int i;
            for(i=start;i<=end;i++){
                if(preorder[idx]==inorder[i]) break;
            }
            idx++;
            node->left=solve(start,i-1,idx,preorder,inorder);
            node->right=solve(i+1, end,idx,preorder,inorder);
            return node;
        }
        return NULL;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        int idx=0;
        return solve(0,preorder.size()-1,idx,preorder,inorder);
    }
};