#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> adj[], int node, vector<int> &vis)
{
  queue<pair<int, int>> que;
  que.push({node, -1});
  vis[node] = 1;

  while (!que.empty())
  {
    pair<int, int> i = que.front();
    que.pop();
    for (int j : adj[i.first])
    {
      if (vis[j] == 1 && j != i.second)
      {
        return true;
      }
      else if (vis[j] == 0)
      {
        vis[j] = 1;
        que.push({j, i.first});
      }
    }
  }
}
bool isCycle(int V, vector<int> adj[])
{
  vector<int> vis(V, 0);
  for (int i = 0; i < V; i++)
  {
    if (vis[i] == 0)
    {
      if (check(adj, i, vis))
      {
        return true;
      }
    }
  }
  return false;
}