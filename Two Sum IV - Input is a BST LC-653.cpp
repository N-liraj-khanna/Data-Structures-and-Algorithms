// tc=o(n)
// sc=o(h)
class Solution {
public:
    void pushLeft(TreeNode* root, stack<TreeNode*>& stk){
        while(root){
            stk.push(root);
            root=root->left;
        }
    }

    void pushRight(TreeNode* root, stack<TreeNode*>& stk){
        while(root){
            stk.push(root);
            root=root->right;
        }
    }

    TreeNode* next(stack<TreeNode*>& stk){
        TreeNode* left=stk.top();
        stk.pop();
        pushLeft(left->right,stk);
        return left;
    }

    TreeNode* before(stack<TreeNode*>& stk){
        TreeNode* right=stk.top();
        stk.pop();
        pushRight(right->left,stk);
        return right;
    }

    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> stk1;
        pushLeft(root,stk1);
        
        stack<TreeNode*> stk2;
        pushRight(root,stk2);
        
        TreeNode* left=stk1.top();
        TreeNode* right=stk2.top();
        while(left->val<=right->val && left!=right){
            if(left->val+right->val==k){
                return true;
            }else if(left->val+right->val>k){
                right=before(stk2);
            }else{
                left=next(stk1);
            }
        }
        return false;
    }
};