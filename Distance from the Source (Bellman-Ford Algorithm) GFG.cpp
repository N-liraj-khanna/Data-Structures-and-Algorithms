// simple method
// tc=o(V*E)
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    void bfs(int S, vector<int>& dist, vector<vector<pair<int,int>>>& adj){
        queue<int> q;
        q.push(S);
        
        while(!q.empty()){
            int top=q.front();
            q.pop();
            
            for(pair<int,int> it: adj[top]){
                if(it.second+dist[top]<dist[it.first]){
                    dist[it.first]=it.second+dist[top];
                    q.push(it.first);
                }
            }
        }
    }
    
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector<int> dist(V,1e8);
        dist[S]=0;
        
        for(int i=0;i<V-1;i++){
            for(auto j: edges){
                int u=j[0], v=j[1], w=j[2];
                if(dist[u]!=1e8 && dist[u] + w < dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }
        
        // Nth relaxation
        for(auto j: edges){
            int u=j[0], v=j[1], w=j[2];
            if(dist[u]!=1e8 && dist[u] + w < dist[v]){
                return {-1};
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends

// TLE Full emthod
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    void bfs(int S, vector<int>& dist, vector<vector<pair<int,int>>>& adj){
        queue<int> q;
        q.push(S);
        
        while(!q.empty()){
            int top=q.front();
            q.pop();
            
            for(pair<int,int> it: adj[top]){
                if(it.second+dist[top]<dist[it.first]){
                    dist[it.first]=it.second+dist[top];
                    q.push(it.first);
                }
            }
        }
    }
    
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector<vector<pair<int,int>>> adj(V,vector<pair<int,int>>());
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        vector<int> dist(V,1e8);
        dist[S]=0;
        
        for(int i=1;i<V;i++){
            bfs(S,dist,adj);
        }
        
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends