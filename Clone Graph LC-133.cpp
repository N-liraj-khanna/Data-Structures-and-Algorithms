// tc=o(V+E)
// sc=o(3N)

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*,Node*>& map){
        if(map.find(node)!=map.end()) return map[node];

        map[node]=new Node(node->val);

        for(Node* neigh: node->neighbors){
            if(map.find(neigh)==map.end()){
                map[node]->neighbors.push_back(dfs(neigh,map));
            }else{
                map[node]->neighbors.push_back(map[neigh]);
            }
        }
        return map[node];
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*,Node*> map;
        dfs(node, map);
        return map[node];
    }
};



// tc=2*o(V+E)
// sc=2*o(3N)
class Solution {
public:
    map<int,vector<int>> bfs_node_to_list(Node* node){
        
        map<int,vector<int>> adj;
        set<int> visited;

        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            Node* front=q.front();
            visited.insert(front->val);
            q.pop();
            vector<int> temp;
            for(Node* neigh: front->neighbors){
                if(visited.find(neigh->val)==visited.end()){
                    q.push(neigh);
                    visited.insert(neigh->val);
                }
                temp.push_back(neigh->val);
            }
            adj[front->val]=temp;
        }
        return adj;
    }

    Node* bfs_list_to_node(map<int,vector<int>> adj){
        unordered_map<int,Node*> mp;
        Node* node=new Node(1);
        mp[1]=node;

        for(int i=1;i<=adj.size();i++){
            for(int j: adj[i]){ 
                if(mp.find(j)==mp.end()){ 
                    Node* temp=new Node(j);
                    mp[i]->neighbors.push_back(temp);
                    mp[j]=temp;
                }else{
                    mp[i]->neighbors.push_back(mp[j]);
                }
            }
        }
        return node;
    }


    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        map<int,vector<int>> adj = bfs_node_to_list(node);
        return bfs_list_to_node(adj);
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/