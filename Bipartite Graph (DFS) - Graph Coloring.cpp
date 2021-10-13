#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool dfs(vector<vector<int>> &graph, int node, int parent, vector<int> &color)
  {
    color[node] = parent;
    for (int i : graph[node])
    {
      if (color[i] == -1)
      {
        if (!dfs(graph, i, 1 - parent, color))
        {
          return false;
        }
      }
      else if (color[i] == color[node])
      {
        return false;
      }
    }
    return true;
  }
  bool isBipartite(vector<vector<int>> &graph)
  {
    vector<int> color(graph.size(), -1);
    for (int i = 0; i < graph.size(); i++)
    {
      if (color[i] == -1)
      {
        if (!dfs(graph, i, 0, color))
        {
          return false;
        }
      }
    }
    return true;
  }
};