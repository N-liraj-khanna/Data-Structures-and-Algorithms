// tc=o(n)
// sc=o(n)

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> res;
        
        queue<TreeNode*> q;
        q.push(root);

        bool flag=true;
        
        while(!q.empty()){
            
            int size=q.size();
            vector<int> temp(size,0);
            int idx=0;

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                
                temp[flag?idx:size-idx-1]=node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                idx++;
            }
            flag=!flag;
            res.push_back(temp);
        }
        return res;
    }
};

// tc=o(n*(n/2))
// sc=o(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> res;
        
        queue<TreeNode*> q;
        q.push(root);

        bool flag=false;
        
        while(!q.empty()){
            
            int size=q.size();
            vector<int> temp;

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                
                temp.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(flag) reverse(temp.begin(),temp.end());
            flag=!flag;
            res.push_back(temp);
        }
        return res;
    }
};