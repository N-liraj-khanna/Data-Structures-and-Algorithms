#1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(cloned);
        
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            
            if(temp->val==target->val) return temp;
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        
        return NULL;
    }
};

#2
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(original);
        q2.push(cloned);
        
        while(!q1.empty()){
            TreeNode* temp1=q1.front();
            TreeNode* temp2=q2.front();
            q1.pop();
            q2.pop();
            
            if(temp1==target) return temp2;
            
            if(temp1->left) q1.push(temp1->left);
            if(temp1->right) q1.push(temp1->right);
            
            if(temp2->left) q2.push(temp2->left);
            if(temp2->right) q2.push(temp2->right);
        }
        
        return NULL;
    }
};