// tc=o(N+n)
// sc=o(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string res="";
        int mini=INT_MAX;
        for(string i: s){
            int t=i.size();
            if(!t) return "";
            mini=min(t,mini);
        }
        for(int i=0;i<mini;i++){
            bool flag=true;
            char c=s[0][i];
            for(int k=1;k<s.size();k++){
                if(s[k][i]!=c){
                    flag=false;
                    break;
                }
            }
            if(flag) res+=c;
            else return res;
        }
        return res;
    }
};