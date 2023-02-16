// tc=o(n)
// tc=o(n)
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=new TreeNode(0);
        int idx=0;
        root->left=solve(0,preorder.size()-1,idx,preorder,inorder);
        return root->left;
    }
};