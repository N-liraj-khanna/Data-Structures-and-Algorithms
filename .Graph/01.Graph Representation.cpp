#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m; 
	
	// declare the adjacent matrix 
	vector<pair<int,int>> adj[n+1]; 
 	// take edges as input 
	for(int i = 0;i<m;i++) {
	    int u, v,wt; 
	    cin >> u >> v >> wt;
	    adj[u].push_back({wt,v}); 
	    adj[v].push_back({wt,u}); 
	}
    
	for(int i = 0;i<sizeof(adj)/sizeof(adj[0]);i++) {
        cout<<i<<" -> ";
        for(auto i: adj[i])
            cout<<"{"<<i.first<<" "<<i.second<<"} ";
        cout<<endl;
    }
        
	return 0;
}