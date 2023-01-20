// tc=o(2^n)*o(n/2)*k
// sc=o(k*x)
class Solution {
public:
    bool pali(string s, int f, int l){
        while(f<=l){
            if(s[f++]!=s[l--]) return false;
        }
        return true;
    }
    void solve(int ind, string s, vector<string> temp, vector<vector<string>>& res){
        if(ind==s.size()){
            res.push_back(temp);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(pali(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,temp,res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        solve(0,s,temp,res);
        return res;
    }
};