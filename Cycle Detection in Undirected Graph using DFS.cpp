#include <bits/stdc++.h>
using namespace std;

bool check(int node, int parent, vector<int> adj[], vector<int> &vis)
{
  vis[node] = 1;
  for (int i : adj[node])
  {
    if (vis[i] == 0)
    {
      if (check(i, node, adj, vis))
      {
        return true;
      }
    }
    else if (i != parent)
    {
      return true;
    }
  }
  return false;
}
bool isCycle(int V, vector<int> adj[])
{
  vector<int> vis(V, 0);
  for (int i = 0; i < V; i++)
  {
    if (vis[i] == 0)
    {
      if (check(i, -1, adj, vis))
      {
        return true;
      }
    }
  }
  return false;
}