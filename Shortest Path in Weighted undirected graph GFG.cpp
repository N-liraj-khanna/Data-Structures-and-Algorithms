//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(n+1,vector<pair<int,int>>());
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<int> parent(n+1,1);
        vector<int> dist(n+1,INT_MAX);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,1});
        dist[1]=0;

        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;

            pq.pop();
            
            for(auto it: adj[node]){
                if(d+it.second<dist[it.first]){
                    dist[it.first]=d+it.second;
                    parent[it.first]=node;
                    pq.push({d+it.second,it.first});
                }
            }
        }
        
        if(dist[n]==INT_MAX) return {-1};
        
        vector<int> res;
        res.push_back(n);
        int node=n;
        while(parent[node]!=node){
            res.push_back(parent[node]);
            node=parent[node];
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
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

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends