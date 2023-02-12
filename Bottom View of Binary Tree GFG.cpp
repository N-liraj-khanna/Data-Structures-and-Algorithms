// tc=o(n)
// sc=o(n)
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        if(!root) return {};
        vector<int> res;
        map<int,int> mp;
        queue<pair<Node*,int>> que;
        que.push({root,0});
        
        while(!que.empty()){
            Node* node=que.front().first;
            int line=que.front().second;
            mp[line]=node->data;
            que.pop();
            if(node->left) que.push({node->left,line-1});
            if(node->right) que.push({node->right,line+1});

        }
        for(auto i: mp){
            res.push_back(i.second);
        }
        return res;
    }
};
// tc=o(n)
// sc=o(n)
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        if(!root) return {};
        vector<int> res;
        unordered_map<int,int> map;
        queue<pair<Node*,int>> que;
        int maxi=0, mini=0;
        que.push({root,0});
        
        while(!que.empty()){
            Node* node=que.front().first;
            int line=que.front().second;
            map[line]=node->data;
            maxi=max(maxi,line);
            mini=min(mini,line);
            que.pop();
            if(node->left) que.push({node->left,line-1});
            if(node->right) que.push({node->right,line+1});

        }
        for(int i=mini;i<=maxi;i++){
            res.push_back(map[i]);
        }
        return res;
    }
};