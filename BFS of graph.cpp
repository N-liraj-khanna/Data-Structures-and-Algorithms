#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], vector<int> &vis, queue<int> &que, vector<int> &res) {
  int curr = que.front();
  res.push_back(curr);
  vis[curr] = 1;
  que.pop();

  for (int i = 0; i < adj[curr].size(); i++) {
    int temp = adj[curr][i];
    if (vis[temp] == 0) {
      vis[temp] = 1;
      res.push_back(temp);
    }
  }
}
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
  vector<int> vis(V, 0);
  vector<int> res;
  queue<int> que;
  for (int i = 0; i < V; i++) {
    if (vis[i] == 0) {
      que.push(i);
      bfs(adj, vis, que, res);
    }
  }
  return res;
}