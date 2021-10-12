#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> adj[], vector<int> &vis, vector<int> &res)
{
	res.push_back(i);
	vis[i] = 1;
	for (int j : adj[i])
	{
		if (vis[j] == 0)
		{
			dfs(j, adj, vis, res);
		}
	}
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
	vector<int> res;
	vector<int> vis(V, 0);
	for (int i = 0; i < V; i++)
	{
		if (vis[i] == 0)
		{
			dfs(i, adj, vis, res);
		}
	}
	return res;
}
