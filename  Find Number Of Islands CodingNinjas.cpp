#include<bits/stdc++.h>
using namespace std;
int getTotalIslands(int** grid, int m, int n){
   vector<vector<bool>> vis(m, vector<bool>(n,false));
   int op=0;
   queue<pair<int,int>> q;

   for(int row=0;row<m;row++){
      for(int col=0;col<n;col++){
         if(grid[row][col]==1 && !vis[row][col]){
            op++;
            q.push({row,col});

            while(!q.empty()){
               int i=q.front().first;
               int j=q.front().second;
               q.pop();

               vis[i][j]=true;
               
               for(int k=i-1;k<=i+1;k+=1){
                  for(int l=j-1;l<=j+1;l+=1){
                     if(k>=0 && k<=m-1 && l>=0 && l<=n-1 && grid[k][l] && !vis[k][l]){
                        q.push({k,l});
                        vis[k][l]=true;
                     }
                  }
               }
               
            }
         }
      }
   }
   return op;
}
