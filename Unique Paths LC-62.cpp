// Best
// TC -> min(O(N),O(M))
// SC -> O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int len=m+n-2;
        long out=1;
        m=min(m,n)-1;
        for(int i=1;i<=m;i++){
            out=out*(len-i+1)/i;
        }
        return (int)out;
    }
};


// Memoization DP
// TC -> O(N*M)
// SC -> O(N*M)
class Solution {
public:
    int unique(int i, int j, int &m, int &n, vector<vector<int>> &memo){
        if(i==m-1 && j==n-1) return 1;
        if(i==m || j==n) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        memo[i][j]=unique(i+1,j,m,n,memo)+unique(i,j+1,m,n,memo);
        return memo[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m,vector<int> (n,-1)); 
        return unique(0,0,m,n, memo);
    }
};

// brute recursion
// TC -> O(2^N)
// SC -> O(d)
class Solution {
public:
    int unique(int i, int j, int &m, int &n, int count){
        if(i==m-1 && j==n-1) return 1;
        if(i==m || j==n) return 0;
        count+=unique(i+1,j,m,n,count)+unique(i,j+1,m,n,count);
        return count;
    }
    int uniquePaths(int m, int n) {
        return unique(0,0,m,n,0);
    }
};