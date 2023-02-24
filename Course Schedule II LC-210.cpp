// khans algo
// tc=o(n)
// sc=o(n)
class Solution {
public:
    vector<int> khansAlgo(int n, vector<vector<int >> & edges) {
        vector<vector<int>> adj(n,vector<int>());
        for(auto i: edges){
            adj[i[1]].push_back(i[0]);
        }

        vector<int> ind(n,0);
        for(int i=0;i<edges.size();i++){
            ind[edges[i][0]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(ind[i]==0)q.push(i);
        }

        vector<int> res;
        while(!q.empty()){
            int front=q.front();
            res.push_back(front);
            q.pop();

            for(int i: adj[front]){
            ind[i]--;
            if(ind[i]==0) q.push(i);
            }
        }
        if(res.size()!=n) return {};
        
        return res;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        return khansAlgo(n,pre);
    }
};