// tc=o(NM)
// sc=o(NM)
class Solution {
public:

    void makeRotten(int i, int j, vector<vector<int>>& grid, queue<pair<int,int>>& q, int n, int m){
        
        if(i>0 && grid[i-1][j]==1){
            q.push({i-1,j});
            grid[i-1][j]=2;
        }
        if(i<n-1 && grid[i+1][j]==1){
            q.push({i+1,j});
            grid[i+1][j]=2;
        }
        if(j>0 && grid[i][j-1]==1){
            q.push({i,j-1});
            grid[i][j-1]=2;
        }
        if(j<m-1 && grid[i][j+1]==1){
            q.push({i,j+1});
            grid[i][j+1]=2;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int timer=0;
        int tot=0;

        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0) tot++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> front=q.front();
                tot++;
                q.pop();
                makeRotten(front.first,front.second,grid,q,n,m);
            }
            if(!q.empty()) timer++;
        }
        
        return (n*m==tot)?timer:-1;
    }
};