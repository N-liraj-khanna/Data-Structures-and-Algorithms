// tc=o(n)
// sc=o(n)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> que;
        que.push({root,0});
        int maxi=0;

        while(!que.empty()){
            int size=que.size();
            int mini=que.front().second;
            maxi=max(maxi,que.back().second-que.front().second+1);
            for(int i=0;i<size;i++){
                TreeNode* node = que.front().first;
                int width = que.front().second-mini;
                que.pop();
                if(node->left) que.push({node->left,(long)2*width+1});
                if(node->right) que.push({node->right,(long)2*width+2});
            }
        }
        return maxi;
    }
};