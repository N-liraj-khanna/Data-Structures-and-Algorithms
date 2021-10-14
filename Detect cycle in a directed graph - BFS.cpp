#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isCyclic(int V, vector<int> adj[])
  {
    vector<int> in(V, 0);
    for (int i = 0; i < V; i++)
    {
      for (int e : adj[i])
      {
        in[e]++;
      }
    }

    queue<int> que;
    int count = 0;

    for (int i = 0; i < in.size(); i++)
    {
      if (in[i] == 0)
      {
        que.push(i);
      }
    }

    while (!que.empty())
    {
      int temp = que.front();
      que.pop();
      count++;
      for (int e : adj[temp])
      {
        in[e]--;
        if (in[e] == 0)
        {
          que.push(e);
        }
      }
    }

    return !(count == V);
  }
};
