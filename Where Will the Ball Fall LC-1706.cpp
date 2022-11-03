// Main solution
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int> out(n,-1);
        
        for(int ball=0;ball<n;ball++){
            int col=ball;
            int row;
            for(row=0;row<m;row++){
                if(col+1<n && grid[row][col]==1 && grid[row][col]==grid[row][col+1]){
                    col++;
                }else if(col-1>=0 && grid[row][col]==-1 && grid[row][col]==grid[row][col-1]){
                    col--;
                }else{
                    break;
                }
            }
            if(row==m) out[ball]=col;
        }
        return out;
    }
};