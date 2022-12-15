// Optimal TC=> 2*O(N^2)  SC=>O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int i,j; 

        for(i=0;i<n;i++){
            for(j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(i=0;i<n;i++){
            for(j=0;j<n/2;j++){
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
};