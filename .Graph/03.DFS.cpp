#include <bits/stdc++.h>
using namespace std;

void dfs(int idx, vector<pair<int, int>> adj[], vector<bool> &visited, vector<int> &dfs_values){

  dfs_values.push_back(idx);
  visited[idx]=true;
  for(auto it: adj[idx]){
    if(!visited[it.second])
      dfs(it.second, adj, visited, dfs_values);
  }

}

vector<int> dfs_of_graph(vector<pair<int,int>> adj[], int N){
  vector<bool> visited(N,false);
  vector<int> dfs_values;

  for(int i=1;i<N;i++){
    if(!visited[i])
      dfs(i, adj, visited, dfs_values);
  }
  return dfs_values;
}


int main(){
  
  int n, m;
  cin >> n >> m;

  // declare the adjacent matrix
  vector<pair<int,int>> adj[n + 1];
  // take edges as input
  for (int i = 0; i < m; i++)
  {
    int u, v, wt;
    cin >> u >> v >>wt;
    adj[u].push_back({wt,v});
    adj[v].push_back({wt,u});
  }
  
  for (int i = 1; i < n+1; i++)
  {
    cout << i << " -> ";
    for (auto e : adj[i])
      cout << "{" << e.first << " " << e.second << "} ";
    cout << endl;
  }
  vector<int> dfs_values = dfs_of_graph(adj,n+1);
  cout<<endl;
  for(auto e : dfs_values)
    cout<<e<<" ";

  return 0;
}