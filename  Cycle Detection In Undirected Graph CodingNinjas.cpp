// dfs
// tc=o(n)
// sc=o(n)
#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visi, int n){
    visi[node]=true;

    for(int i: adj[node]){
        if(!visi[i]){
            if(dfs(i,node,adj,visi,n)){
                return true;
            }
        }
        else if(parent!=i) return true;
    }
    
    return false;

}

string cycleDetection(vector<vector<int>>& edges, int n, int m){

    vector<vector<int>> adj(n+1,vector<int>());
    for(int i=0;i<m;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> visi(n+1,false);
    for(int i=1;i<=n;i++){
        if(!visi[i]){
            if(dfs(i,-1,adj, visi,n)) return "Yes";
        }
    }
    
    return "No";
}




// bfs
// tc=o(n)
// sc=o(n)
#include<bits/stdc++.h>
using namespace std;
string cycleDetection (vector<vector<int>>& edges, int n, int m){

    vector<vector<int>> adj(n+1,vector<int>());
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> visi(n+1,false);

    for(int node=1;node<=n;node++){
        if(visi[node]==false){

            queue<pair<int,int>> q;
            q.push({node,-1});

            while(!q.empty()){

                pair<int,int> front=q.front();
                visi[front.first]=true;
                q.pop();

                for(int i: adj[front.first]){
                    if(i==front.second) continue;
                    else if(visi[i]) return "Yes";
                    else q.push({i,front.first});
                }
            }
        }
    }
    return "No";
}
