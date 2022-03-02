#include <bits/stdc++.h>
using namespace std;

stack<int> topo(int node, vector<pair<int,int>> adj[], stack<int> &stk, vector<int> &vis){
  vis[node]=1;
  for(pair<int,int> i: adj[node]){
    if(vis[i.first]==0){
      topo(i.first, adj, stk, vis);
    }
  }
  stk.push(node);
  return stk;
}

vector<int> shortestPath(int n, vector<pair<int,int>> adj[], int source){
  // Topo Sort in Stack
  vector<int> vis(n, 0);
  stack<int> stk;
  for(int i=0;i<n;i++){
    if(vis[i]==0)
      topo(i, adj, stk, vis);
  }

  // Shortest Path in DAG
  vector<int> dist(n,INT_MAX);
  dist[source]=0;

  while(!stk.empty()){
    int node=stk.top();
    stk.pop();

    if(dist[node]!=INT_MAX){
      for(pair<int,int> e: adj[node]){
        if(dist[e.first]>dist[node]+e.second)
          dist[e.first]=dist[node]+e.second;
      }
    }
  }

  return dist;
} 

int main()
{
  int n,m;
  cout<<"Enter the num of nodes and the edges/connections: ";
  cin>>n>>m;
  vector<pair<int,int>> adj[n+1];

  cout<<"Enter the connections of paths(from what to what ex. A->B which is also B->A since it's an undirected graph) =>\n";
  for(int i=0;i<m;i++){
    int u, v, wt;
    cin>>u>>v>>wt;
    adj[u].push_back({v,wt});
  }

  vector<int> res = shortestPath(n, adj, 0);  
  for(auto i: res)
    if(i==INT_MAX)
      cout<<"INF ";
    else
      cout<<i<<" ";
  cout<<endl;

	return 0;
}