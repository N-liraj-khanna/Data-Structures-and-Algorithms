// tc=o(n)
// sc=o(n)
class Solution {
public:
    TreeNode* solve(int start, int end, int& idx, vector<int>& postorder, vector<int>& inorder){
        if(start>end) return NULL;
        if(idx>=0){
            TreeNode* node=new TreeNode(postorder[idx]);
            int i;
            for(i=start;i<=end;i++){
                if(postorder[idx]==inorder[i]) break;
            }
            idx--;
            node->right=solve(i+1,end,idx,postorder,inorder);
            node->left=solve(start,i-1,idx,postorder,inorder);
            return node;
        }
        return NULL;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root=new TreeNode(0);
        int idx=postorder.size()-1;
        root->left=solve(0,postorder.size()-1,idx,postorder,inorder);
        return root->left;
    }
};