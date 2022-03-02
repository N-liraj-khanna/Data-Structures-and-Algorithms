#include <bits/stdc++.h>
using namespace std;

vector<int> getIndegree(int V, vector<int> adj[])
{
  vector<int> indegree(V, 0);
  for (int i = 0; i < V; i++)
  {
    for (int e : adj[i])
    {
      indegree[e]++;
    }
  }
  return indegree;
}

vector<int> bfs(vector<int> adj[], vector<int> in, queue<int> que)
{
  vector<int> res;

  for (int i = 0; i < in.size(); i++)
  {
    if (in[i] == 0)
    {
      que.push(i);
      res.push_back(i);
    }
  }

  while (!que.empty())
  {
    int temp = que.front();
    que.pop();
    for (int e : adj[temp])
    {
      in[e]--;
      if (in[e] == 0)
      {
        res.push_back(e);
        que.push(e);
      }
    }
  }

  return res;
}

vector<int> topoSort(int V, vector<int> adj[])
{
  queue<int> que;
  vector<int> in = getIndegree(V, adj);

  return bfs(adj, in, que);
}
