// Same approach but memoization
// all the below will work  with memeoization
// tc=o(n^3)
// sc=o(m*m)+o(300)
class Solution {
public:
    bool solve(int start,string& s,int n, unordered_set<string>& set,vector<bool>& dp){
        if(start==n) return true;
        if(!dp[start]) return false;
        string var="";
        for(int i=start;i<s.size();i++){
            var+=s[i];
            if(set.find(var)!=set.end()){
                if(solve(i+1,s,n,set,dp)) return true;
            }
        }
        return dp[start]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        vector<bool> dp(301,true);
        for(int i=0;i<wordDict.size();i++){
            set.insert(wordDict[i]);
        }
        return solve(0,s,s.size(),set,dp);
    }
};

// TLE a bit better
class Solution {
public:
    bool solve(int start,string& s,int n, unordered_set<string>& set){
        if(start==n) return true;
        string var="";
        for(int i=start;i<s.size();i++){
            var+=s[i];
            if(set.find(var)!=set.end()){
                if(solve(i+1,s,n,set)) return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(int i=0;i<wordDict.size();i++){
            set.insert(wordDict[i]);
        }
        return solve(0,s,s.size(),set);
    }
};

// TLE
// tc=o(M^N)
// sc=o(N)
class Solution {
public:
    bool solve(string temp, int t_len, string& s,int n, vector<string>& dict){
        if(temp==s) return true;
        if(t_len>n) return false;
        for(int i=0;i<dict.size();i++){
            if(solve(temp+dict[i],t_len+dict[i].size(),s,n,dict)) return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve("", 0, s, s.size(), wordDict);
    }
};