// DFS

class Solution
{
public:
    //Function to detect cycle in an undirected graph.
    bool checkCycle(vector<int> adj[], int node, int parent, vector<bool> &visited)
    {

        visited[node] = 1;

        for (auto e : adj[node])
        {
            if (!visited[e])
                if (checkCycle(adj, e, node, visited))
                    return true;
                else if (e != parent)
                    return true;
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V + 1, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (checkCycle(adj, i, -1, visited))
                    return true;
            }
        }
        return false;
    }
};

// BFS
class Solution
{
public:
    //Function to detect cycle in an undirected graph.

    bool checkCycle(vector<int> adj[], int node, vector<bool> &visited)
    {
        queue<pair<int, int>> que;
        que.push({node, -1});
        visited[node] = 1;

        while (!que.empty())
        {

            pair<int, int> temp = que.front();
            que.pop();

            for (auto e : adj[temp.first])
            {
                if (!visited[e])
                {
                    que.push({e, temp.first});
                    visited[e] = 1;
                }
                else if (e != temp.second)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int N, vector<int> adj[])
    {
        vector<bool> visited(N, 0);

        for (int i = 0; i < N; i++)
        {
            if (visited[i] == 0)
            {
                if (checkCycle(adj, i, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
