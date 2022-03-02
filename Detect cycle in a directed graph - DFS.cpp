#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int> adj[], int &node, vector<int> &vis, vector<int> &dfs_vis)
{
  vis[node] = 1;
  dfs_vis[node] = 1;

  for (int e : adj[node])
  {
    if (vis[e] == 0)
    {
      if (dfs(adj, e, vis, dfs_vis))
      {
        return true;
      }
    }
    else if (dfs_vis[e] == 1)
    {
      return true;
    }
  }
  dfs_vis[node] = 0;
  return false;
}
bool isCyclic(int V, vector<int> adj[])
{
  vector<int> vis(V, 0);
  vector<int> dfs_vis(V, 0);
  for (int i = 0; i < V; i++)
  {
    if (!vis[i])
    {
      if (dfs(adj, i, vis, dfs_vis))
      {
        return true;
      }
    }
  }
  return false;
}