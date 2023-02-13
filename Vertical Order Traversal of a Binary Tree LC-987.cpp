// tc=o(n*logn*logn*logn)
// tc=o(n)
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int,map<int,multiset<int>>> mp;
        stack<pair<TreeNode*,pair<int,int>>> stk;
        stk.push({root,{0,0}});

        while(!stk.empty()){

            TreeNode* node=stk.top().first;
            int line=stk.top().second.first;
            int lvl=stk.top().second.second;
            stk.pop();
            
            mp[line][lvl].insert(node->val);

            if(node->right)
                stk.push({node->right,{line+1, lvl+1}});

            if(node->left)
                stk.push({node->left,{line-1, lvl+1}});     
            
        }
        for(auto i: mp){    
            vector<int> temp;
            for(auto j: i.second){
                for(auto k: j.second){
                    temp.push_back(k);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};