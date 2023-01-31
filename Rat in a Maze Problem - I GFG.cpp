// tc=o(4^(n*n))
// sc=o(n*n)
class Solution{
    public:
    void solve(int row, int col, string& temp, vector<vector<int>> &m, vector<vector<bool>>& seen, vector<string>& res,int n){
        if(row==n-1 && col==n-1 && m[row][col]==1){
          res.push_back(temp);
            return;
        } 
        if(row<0 || col<0 || row>=n || col>=n || m[row][col]!=1 || seen[row][col]==1) return;
    
        seen[row][col]=1;
    
        solve(row-1,col,temp+'U',m,seen,res,n);
        solve(row,col+1,temp+'R',m,seen,res,n);
        solve(row,col-1,temp+'L',m,seen,res,n);
        solve(row+1,col,temp+'D',m,seen,res,n);
    
        seen[row][col]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        string t="";
        vector<vector<bool>> seen(n,vector<bool>(n,0));
        solve(0,0,t,m,seen,res,n);
        return res;
    }
};