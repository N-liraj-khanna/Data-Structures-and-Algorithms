// DFS
class Solution
{
	public:
	void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &stk){
	    if(vis[node])
	        return;
	    vis[node]=1;   
       for(int e: adj[node]){
           if(!vis[e]){
               dfs(e, adj, vis, stk);
           }
       }
       stk.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> vis(V,0);
	    stack<int> stk;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i])
    	        dfs(i, adj, vis, stk);
        }
        vis.clear();
        while(!stk.empty()){
            int e=stk.top();
            stk.pop();
            vis.push_back(e);
        }
        return vis;
	}
};
