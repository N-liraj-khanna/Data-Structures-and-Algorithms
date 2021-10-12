#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cout<<"Enter the num of nodes and the edges/connections: ";
  cin>>n>>m;
  vector<int> adj[n+1];

  cout<<"Enter the connections of paths(from what to what ex. A->B which is also B->A since it's an undirected graph) =>\n";
  for(int i=0;i<m;i++){
    int u, v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i=0;i<n;i++){
    cout<<i<<"->";
    for(int j=0;j<adj[i].size();j++){
      cout<<adj[i][j]<<" ";
    }
      cout<<endl;
  }

	return 0;
}