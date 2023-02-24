// khans algo
// tc=o(n)
// sc=o(n)

#include<bits/stdc++.h> 
using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int,int>> & edges) {
  vector<vector<int>> adj(n+1,vector<int>());

  for(int i=0;i<edges.size();i++){
    adj[edges[i].first].push_back(edges[i].second);
  }

  vector<bool> vis(n+1,false);
  vector<bool> dfsvis(n+1,false);

  for(int node=1;node<=n;node++){
    if(!vis[node]){
      
      queue<int> q;
      q.push(node);

      while(!q.empty()){
        int front=q.front();
        vis[node]=true;
        dfsvis[node]=true;
        q.pop();

        for(int i: adj[front]){
          if(!vis[i]){
            q.push(i);
          }else if(dfsvis[i]){
            return true;
          }
        }
        dfsvis[node]=false;
      }
    }
  }
  return false;
}

// dfs
// tc=o(n)
// sc=o(n)
#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<vector<int>> adj(n+1,vector<int>());
  for(auto i: edges){
    adj[i.first].push_back(i.second);
  }

  vector<int> ind(n+1,0);
  for(int i=0;i<edges.size();i++){
    ind[edges[i].second]++;
  }

  queue<int> q;
  for(int i=1;i<=n;i++){
    if(ind[i]==0)q.push(i);
  }

  while(!q.empty()){
    int front=q.front();
    q.pop();

    for(int i: adj[front]){
      ind[i]--;
      if(ind[i]==0) q.push(i);
    }
  }

  for(int i=1;i<=n;i++){
    if(ind[i]!=0) return true;
  }

  return false;
}



// dfs
// tc=o(n)
// sc=o(n)
#include<bits/stdc++.h> 
using namespace std;

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

int detectCycleInDirectedGraph(int n, vector<pair<int,int>> & edges) {
  
  vector<vector<int>> adj(n+1,vector<int>());

  for(int i=0;i<edges.size();i++){
    adj[edges[i].first].push_back(edges[i].second);
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