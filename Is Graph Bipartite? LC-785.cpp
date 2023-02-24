// dfs
// tc=o(n)
// sc=o(n)
class Solution {
public:

    bool dfs(int node, int prev, vector<int>& color, vector<vector<int>>& graph) {
        color[node]=prev;

        for(int i: graph[node]){
            if(color[i]==-1){
                if(!dfs(i,!prev, color, graph)) return false;
            }else if(color[i]==prev) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);

        for(int node=0;node<graph.size();node++){
            if(color[node]==-1){
                if(!dfs(node, 0, color, graph)) return false;
            }
        }
        return true;
    }
};

// bfs
// tc=o(n)
// sc=o(n)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        queue<pair<int,int>> q;

        for(int node=0;node<graph.size();node++){
            if(color[node]==-1){
                q.push({node,0});
                color[node]=0;

                while(!q.empty()){
                    
                    pair<int,int> front=q.front();
                    q.pop();
                    
                    for(int i: graph[front.first]){
                        if(color[i]==-1){
                            color[i]=!front.second;
                            q.push({i,!front.second});
                        }else if(color[i]==front.second){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};