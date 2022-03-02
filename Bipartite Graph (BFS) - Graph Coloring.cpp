#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool bfs(vector<vector<int>> &graph, int node, vector<int> &color)
  {
    queue<int> que;
    que.push(node);
    color[node] = 0;

    while (!que.empty())
    {
      int temp = que.front();
      que.pop();
      for (int i : graph[temp])
      {
        if (color[i] == -1)
        {
          que.push(i);
          color[i] = 1 - color[temp];
        }
        else if (color[i] == color[temp])
        {
          return false;
        }
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
        if (!bfs(graph, i, color))
        {
          return false;
        }
      }
    }
    return true;
  }
};