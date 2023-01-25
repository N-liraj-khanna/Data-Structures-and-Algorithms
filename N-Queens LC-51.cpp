// tc=o(fact(n)*n)
// sc=o(n)
class Solution {
public:
    void solve(int col, vector<string>& temp, int& n, vector<int>& left, vector<int>& up, vector<int>& down, vector<vector<string>>& res){
      if (col == n) {
        res.push_back(temp);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (left[row] == 0 && down[row + col] == 0 && up[n - 1 + col - row] == 0) {
          temp[row][col] = 'Q';
          left[row] = 1;
          down[row + col] = 1;
          up[n - 1 + col - row] = 1;
          solve(col + 1, temp, n, left, up, down, res);
          temp[row][col] = '.';
          left[row] = 0;
          down[row + col] = 0;
          up[n - 1 + col - row] = 0;
        }
      }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n,string(n,'.'));
        vector<vector<string>> res;
        vector<int> left(n, 0);
        vector<int> up(2 * n - 1, 0);
        vector<int> down(2 * n - 1, 0);

        solve(0,temp,n,left, up, down,res);
        return res;
    }
};

// tc=o(fact(n)*n)
// sc=o(n*n)
class Solution {
public:
    bool check(int row, int col, int n, vector<string>& temp){
        for(int i=col;i>=0;i--){
            if(temp[row][i]=='Q') return false;
        }
        for(int i=row, j=col;i>=0 && j>=0;i--,j--){
            if(temp[i][j]=='Q') return false;
        }
        for(int i=row, j=col;i<n && j>=0;i++,j--){
            if(temp[i][j]=='Q') return false;
        }
        return true;
    }
    void solve(int col, vector<string>& temp, int& n, vector<vector<string>>& res){
        if(col==n){
            res.push_back(temp);
        }
        for(int i=0;col<n && i<n;i++){
            if(check(i,col,n,temp)){
                temp[i][col]='Q';
                solve(col+1,temp, n, res);
                temp[i][col]='.';
            }
        }   
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n,string(n,'.'));
        vector<vector<string>> res;

        solve(0,temp,n,res);
        return res;
    }
};