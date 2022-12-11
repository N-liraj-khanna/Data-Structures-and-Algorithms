//  Best optimized TC=>2*O(M*N)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        bool col=true;

        for(int i=0;i<m;i++){
            if(matrix[i][0]==0) col=false;
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=matrix[0][j]=0;
                }
            }
        }

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
            if(!col) matrix[i][0]=0;
        }
    }
};

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

//  approach of storing zeroes index and changing em
class Solution {
public:
    void makeZeroes(vector<vector<int>>& matrix, int x, int y, int& m, int& n){
        for(int i=0;i<n;i++){
            matrix[x][i]=0;
        }
        for(int i=0;i<m;i++){
            matrix[i][y]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m=matrix.size(), n=matrix[0].size();
        vector<pair<int,int>> zeroes;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    zeroes.push_back({i,j});
                }
            }    
        }
        for(auto i: zeroes){
            makeZeroes(matrix, i.first, i.second, m, n);
        }
    }
};

// Another approach on storing the indices in set so less computation and storage space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m=matrix.size(), n=matrix[0].size();
        unordered_set<int> left;
        unordered_set<int> down;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    left.insert(i);
                    down.insert(j);
                }
            }    
        }
        
        for(auto x: left){
            for(int i=0;i<n;i++){
                matrix[x][i]=0;
            }
        }
        for(auto y: down){
            for(int i=0;i<m;i++){
                matrix[i][y]=0;
            }
        }
    }
};

// Two vectors, row and column
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<int> row;
        vector<int> col;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        for(int i=0;i<row.size();i++){
            for(int j=0;j<n;j++){
                matrix[row[i]][j]=0;
            }
        }

        for(int i=0;i<col.size();i++){
            for(int j=0;j<m;j++){
                matrix[j][col[i]]=0;
            }
        }
    }
};