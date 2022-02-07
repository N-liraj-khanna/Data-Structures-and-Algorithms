class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> max_row;
        vector<int> max_col;
        int n=grid.size();
        
        for(int i=0;i<n;i++){
            int max1=0;
            int max2=0;
            for(int j=0;j<n;j++){
                max1=max(max1,grid[i][j]);
                max2=max(max2,grid[j][i]);
            }   
            max_row.push_back(max1);
            max_col.push_back(max2);
        }
        
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=abs(grid[i][j]-min(max_row[i],max_col[j]));
            }
        }
        return sum;
    }
};