#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &stk)
{
  vis[node] = 1;
  for (int e : adj[node])
  {
    if (!vis[e])
    {
      dfs(e, adj, vis, stk);
    }
  }
  stk.push(node);
}
vector<int> topoSort(int V, vector<int> adj[])
{
  vector<int> vis(V, 0);
  vector<int> res;
  stack<int> stk;
  for (int i = 0; i < V; i++)
  {
    if (!vis[i])
    {
      dfs(i, adj, vis, stk);
    }
  }
  while (!stk.empty())
  {
    res.push_back(stk.top());
    stk.pop();
  }
  return res;
}