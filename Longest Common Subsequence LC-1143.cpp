// iterative
// tc=o(n*m)
// sc=o(n*m)
class Solution {
public:

    int longestCommonSubsequence(string t1, string t2) {
        vector<vector<int>> dp(t1.size()+1, vector<int>(t2.size()+1,0));

        for(int i=t1.size()-1;i>=0;i--){
            for(int j=t2.size()-1;j>=0;j--){
                if(t1[i]==t2[j]){
                    dp[i][j] = dp[i+1][j+1]+1;
                }else{
                    dp[i][j]=max(dp[i][j+1] , dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
};

// recursive
// tc=o(n*m)
// sc=o(n*m)
class Solution {
public:
    int bottomup(int i, int j, string& t1, string& t2, vector<vector<int>>& dp){
        if(i==t1.size() || j==t2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(t1[i]==t2[j]){
            dp[i][j] = bottomup(i+1,j+1,t1,t2,dp)+1;
            return dp[i][j];
        }else{
            dp[i][j]=max(bottomup(i,j+1,t1,t2,dp) , bottomup(i+1,j,t1,t2,dp));
            return dp[i][j];
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(),-1));
        return bottomup(0,0,text1,text2,dp);
    }
};