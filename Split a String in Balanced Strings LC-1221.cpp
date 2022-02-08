class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt=0, res=0;
        for(int i=0;i<s.size();i++){
            cnt+=(s[i]=='R')?1:-1;
            if(cnt==0) res++;
        }
        return res;
    }
};