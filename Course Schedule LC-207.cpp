// detect a cycle in directed graph
// tc=o(v+e)
// tc=o(n+n+n)
class Solution {
public:
    int detectCycle(int n, vector<vector<int >> & edges) {
    vector<vector<int>> adj(n+1,vector<int>());
    for(auto i: edges){
        adj[i[0]].push_back(i[1]);
    }

    vector<int> ind(n+1,0);
    for(int i=0;i<edges.size();i++){
        ind[edges[i][1]]++;
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(ind[i]==0)q.push(i);
    }

    int cnt=0;
    while(!q.empty()){
        int front=q.front();
        cnt++;
        q.pop();

        for(int i: adj[front]){
        ind[i]--;
        if(ind[i]==0) q.push(i);
        }
    }


    return !(cnt==n);
    }


    bool canFinish(int n, vector<vector<int>>& pre) {
        return !detectCycle(n,pre);
    }
};
// detect a cycle in directed graph
// tc=o(v+e)
// tc=o(n+n+n)
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& vis,vector<bool>& dfsvis){
    vis[node]=true;
    dfsvis[node]=true;

    for(int i:adj[node]){
        if(!vis[i]){
        if(dfs(i,adj,vis,dfsvis)) return true;
        }else if(dfsvis[i]){
        return true;
        }
    }
    
    dfsvis[node]=false;
    return false;
    }

    int detectCycle(int n, vector<vector<int>> & edges) {
    
    vector<vector<int>> adj(n+1,vector<int>());

    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<bool> vis(n+1,false);
    vector<bool> dfsvis(n+1,false);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
        if(dfs(i,adj,vis,dfsvis)) return true;
        }
    }
    return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        return !detectCycle(n,pre);
    }
};