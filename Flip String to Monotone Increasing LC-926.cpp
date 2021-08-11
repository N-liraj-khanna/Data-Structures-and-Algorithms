class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zto=0, ones=0;
        int ans=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')
                zto++;
            else
                ones++;
            
            zto=min(ones, zto);
        }
        return zto;
    }
};