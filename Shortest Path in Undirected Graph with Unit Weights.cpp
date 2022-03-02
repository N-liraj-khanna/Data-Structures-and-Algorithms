#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, vector<int> adj[], int source){
  vector<int> dist(n, INT_MAX);
  dist[source]=0;
  
  queue<int> q;
  q.push(source);
  
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(int e: adj[node]){
      if(dist[e]>dist[node]+1){
        dist[e]=dist[node]+1;
        q.push(e);
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
  vector<int> adj[n+1];

  cout<<"Enter the connections of paths(from what to what ex. A->B which is also B->A since it's an undirected graph) =>\n";
  for(int i=0;i<m;i++){
    int u, v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> res = shortestPath(n, adj, 0);  
  for(auto i: res)
    cout<<i<<" ";
  cout<<endl;

	return 0;
}