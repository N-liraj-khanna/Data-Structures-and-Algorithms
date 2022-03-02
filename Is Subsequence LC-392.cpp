Day 1:
Question 1: 392. Is Subsequence

// Recursive approach
class Solution {
public:
    bool isSub(string s, string t, int n, int m){
        if(n==0) return true;
        if(m==0) return false;
        if(s[n-1]==t[m-1])
            return isSub(s, t, n-1, m-1);
        else
            return isSub(s, t, n, m-1);
    }
    bool isSubsequence(string s, string t) {
        return isSub(s, t, s.size(), t.size());
    }
};

// Two pointer - better but similar approach to Recursive
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        
        while(!m==0 && !n==0){
            if(s[n-1]==t[m-1]){
                m--;n--;
            }else{
                m--;
            }
        }
        return n==0;
    }
};