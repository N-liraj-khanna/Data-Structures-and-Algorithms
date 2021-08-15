#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<pair<int, int>> adj[], int N){

  vector<bool> visited(N+1, 0);
  vector<int> bfs; 
  queue<int> que;

  for (int i = 1; i <= N;i++){
    if(visited[i]==0){
      que.push(i);

      while(!que.empty()){
        int idx = que.front();
        que.pop();
        
        cout<<idx<<" ";
        bfs.push_back(idx);

        for(pair<int,int> e: adj[idx]){
          if(visited[e.second]==0){
            que.push(e.second);
            visited[e.second]=1;
          }
        }
        visited[idx]=1;
      }

    } 
  }
  return bfs;
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
  
  for (int i = 0; i < n+1; i++)
  {
    cout << i << " -> ";
    for (auto e : adj[i])
      cout << "{" << e.first << " " << e.second << "} ";
    cout << endl;
  }

    // for (int i = 0; i < graph.size(); i++)
  // {
  //   cout << i << " -> ";
  //   for (auto e : graph[i])
  //     cout << e << " ";
  //   cout << endl;
  // }

  bfs(adj, n);

  return 0;
}