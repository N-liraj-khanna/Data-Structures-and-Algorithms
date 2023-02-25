// tc=3*o(n+e)
// sc=2*o(v+e)+2*o(n)
#include<bits/stdc++.h>
using namespace std;

void toposort(int node, vector<vector<int>> &adj, stack<int>& stk,vector<bool>& vis) {
    vis[node]=true;
    for(int i: adj[node]){
        if(!vis[i]){
            toposort(i,adj,stk,vis);
        }
    }
    stk.push(node);

}

void transpose(vector<vector<int>>& adj, vector<vector<int>>& trans){
    for(int i=0;i<adj.size();i++){
        for(int j=0;j<adj[i].size();j++){
            trans[adj[i][j]].push_back(i);
        }
    }
}

void dfs_trans(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& temp){
    vis[node]=true;
    temp.push_back(node);

    for(int i: adj[node]){
        if(!vis[i]){
            dfs_trans(i,adj,vis,temp);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges){
    
    vector<vector<int>> adj(n,vector<int>());
    for(auto i: edges){
        adj[i[0]].push_back(i[1]);
    }

    // topo sort
    stack<int> stk;
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            toposort(i,adj,stk,vis);
        }
    }
    
    // transpose
    vector<vector<int>> trans(n,vector<int>());
    transpose(adj,trans);
    
    // dfs wrt finish time
    vector<vector<int>> res;
    fill(vis.begin(),vis.end(),false);
    
    while(!stk.empty()){
        vector<int> temp;
        
        if(!vis[stk.top()]){
            dfs_trans(stk.top(),trans,vis, temp);
        }
        
        res.push_back(temp);
        stk.pop();
    }
    

    return res;
}