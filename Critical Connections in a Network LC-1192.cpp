// tc=o(n)
// sc=o(4*n)
class Solution {
public:
    void dfs(int node, int parent, int& step, vector<vector<int>>& adj, vector<int>& time, vector<int>& low, vector<vector<int>>& res){
        
        time[node]=low[node]=step;
        step++;

        for(int it: adj[node]){
            if(parent==it) continue;
            
            if(time[it]==-1){

                dfs(it,node,step,adj,time,low,res);
                
                if(low[it]>time[node]){
                    res.push_back({it,node});
                }
            }
            low[node]=min(low[it],low[node]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {

        vector<vector<int>> adj(n,vector<int>());
        for(auto it: conn){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<vector<int>> res;
        vector<int> time(n,-1);
        vector<int> low(n,-1);
        int step=1;

        dfs(0,-1,step,adj,time,low,res);
        return res;
    }
};