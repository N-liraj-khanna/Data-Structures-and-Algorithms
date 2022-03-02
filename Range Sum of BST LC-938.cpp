/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode*> q;
        q.push(root);
        
        int sum=0;
        
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            
            if(low<=temp->val && high>=temp->val) sum+=temp->val;
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        
        return sum;
    }
};