// bfs
// tc=o(n)
// sc=o(n)
#include <bits/stdc++.h> 

void dfs(int node, vector<vector<int>>& adj, stack<int>& stk, vector<bool>& vis){
    vis[node]=true;

    for(int i: adj[node]){
        if(!vis[i]) dfs(i,adj,stk,vis);
    }
    
    stk.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    vector<vector<int>> adj(v,vector<int>());
    for(auto i: edges){
        adj[i[0]].push_back(i[1]);
    }

    stack<int> stk;
    vector<bool> vis(v,false);
    for(int node=0;node<v;node++){
        if(!vis[node]) dfs(node,adj,stk, vis);
    }
    
    vector<int> res;
    while(!stk.empty()){
        res.push_back(stk.top());
        stk.pop();
    }

    return res;
}

// bfs
// tc=o(n)
// sc=o(n)
#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    vector<vector<int>> adj(v,vector<int>());
    for(auto i: edges){
        adj[i[0]].push_back(i[1]);
    }
    
    vector<int> ind(v,0);
    for(auto i: adj){
        for(int j: i){
            ind[j]++;
        }
    }

    queue<int> q;
    for(int i=0;i<ind.size();i++){
        if(ind[i]==0) q.push(i);
    }

    vector<int> res;
    for(int node=0;node<v;node++){
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            res.push_back(front);
            
            for(int i: adj[front]){
                ind[i]--;
                if(ind[i]==0){
                    q.push(i);

                }
            }
        }
    }

    return res;
}