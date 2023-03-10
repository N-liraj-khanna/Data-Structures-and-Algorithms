// tc=o(N^M)
// sc=o(N)
#include <bits/stdc++.h> 
bool safe(int c, vector<int>& mat, vector<int>& color){
    for(int i=0;i<mat.size();i++){
        if(mat[i]==1 && color[i]==c) return false;
    }
    return true;
}
bool solve(int node, vector<vector<int>>& mat, vector<int>& color, int m, int n){
    if(node==n) return true;

    for(int c=1;c<=m;c++){
        if(safe(c, mat[node], color)){
            color[node]=c;
            if(solve(node+1,mat,color,m,n)) return true;
            
            color[node]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    int n=mat.size();
    vector<int> color(n,0);
    return solve(0,mat,color,m,n)?"YES":"NO";
}