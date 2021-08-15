// Unweighted
for (int i = 0; i < graph.size(); i++){
  cout << i << " -> ";
  for (auto e : graph[i])
    cout << e << " ";
  cout << endl;
}

//Weighted
  for (int i = 0; i < n+1; i++)
  {
    cout << i << " -> ";
    for (auto e : adj[i])
      cout << "{" << e.first << " " << e.second << "} ";
    cout << endl;
  }