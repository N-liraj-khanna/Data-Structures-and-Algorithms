#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        queue<pair<int,int>> q;
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        q.push({0, S});
        
        while(!q.empty()){
            pair<int,int> node = q.front();
            q.pop();
            for(auto e: adj[node.second]){
                int d=dist[node.second]+e[1];

                if(d<dist[e[0]]){
                    dist[e[0]]=d;
                    q.push({d, e[0]});
                }
            }
        }
        return dist;
    }
};