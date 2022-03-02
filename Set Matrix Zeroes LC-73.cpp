  
// TC=>O(N^2)+O(Num of zeroes * max(M,N))
// SC=>O(Num of zeroes)
  
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeroes;
        int N=matrix.size(),M=matrix[0].size();
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(matrix[i][j]==0){
                    zeroes.push_back({i,j});
                }
            }
        }
        
        for(int z=0;z<zeroes.size();z++){
            for(int i=0;i<max(N,M);i++){
                matrix[zeroes[z].first][min(i,M-1)]=0;
                matrix[min(i,N-1)][zeroes[z].second]=0;
            }
        }
    }
};