class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        int op=0;
        queue<pair<int,int>> q;

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]=='1' && !vis[row][col]){
                    op++;
                    q.push({row,col});

                    while(!q.empty()){
                        int i=q.front().first;
                        int j=q.front().second;
                        q.pop();

                        vis[i][j]=true;

                        if(i>0 && grid[i-1][j]=='1' && !vis[i-1][j]){
                             q.push({i-1,j});
                             vis[i-1][j]=true;
                        }
                        if(j>0 && grid[i][j-1]=='1' && !vis[i][j-1]){
                             q.push({i,j-1});
                             vis[i][j-1]=true;
                        }
                        if(i<m-1 && grid[i+1][j]=='1' && !vis[i+1][j]){
                             q.push({i+1,j});
                             vis[i+1][j]=true;
                        }
                        if(j<n-1 && grid[i][j+1]=='1' && !vis[i][j+1]){
                             q.push({i,j+1});
                             vis[i][j+1]=true;
                        }
                    }
                }
            }
        }
        return op;
    }
};