
class Solution
{
public:
  bool dfs(vector<int> adj[], int node, vector<int> &vis, vector<int> &vis_dfs)
  {
    vis[node] = 1;
    vis_dfs[node] = 1;
    for (int e : adj[node])
    {
      if (!vis[e])
      {
        if (dfs(adj, e, vis, vis_dfs))
          return true;
      }
      else if (vis_dfs[e])
      {
        return true;
      }
    }
    vis_dfs[node] = 0;
    return false;
  }

  bool isCyclic(int V, vector<int> adj[])
  {

    vector<int> vis(V, 0);
    vector<int> vis_dfs(V, 0);

    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        if (dfs(adj, i, vis, vis_dfs))
        {
          return true;
        }
      }
    }
    return false;
  }
};
