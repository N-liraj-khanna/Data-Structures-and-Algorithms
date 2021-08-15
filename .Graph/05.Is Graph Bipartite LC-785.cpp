//DFS Approach
class Solution {
public:   
    bool checkBipartiteWithDFS(vector<vector<int>>& graph, int node, vector<int> &color) {
        for(int e: graph[node]){
            if(color[e]==-1){
                color[e]=1-color[node];
                if(!checkBipartiteWithDFS(graph, e, color))
                    return false;
            }else if(color[e]==color[node])
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
               
        int N=graph.size();
        vector<int> color(N,-1);
        
        for(int i=0;i<N;i++){
            if(color[i]==-1){
                // if(!checkBipartiteWithBFS(graph, i, color))
                color[i]=0;
                if(!checkBipartiteWithDFS(graph, i, color))
                    return false;
            }
        }
        return true;
    }
};

// BFS Approach
class Solution {
public:
    bool checkBipartiteWithBFS(vector<vector<int>>& graph, int node, vector<int> &color) {
        queue<int> que;
        que.push(node);
        color[node]=0;
        
        while(!que.empty()){
            int first=que.front();
            que.pop();
            
            for(int e: graph[first]){
                if(color[e]==-1){
                    que.push(e);
                    color[e]=1-color[first];
                }else if(color[e]==color[first]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int N=graph.size();
        vector<int> color(N,-1);
        
        for(int i=0;i<N;i++){
            if(color[i]==-1){
                if(!checkBipartiteWithBFS(graph, i, color))
                    return false;
            }
        }
        return true;
    }
};