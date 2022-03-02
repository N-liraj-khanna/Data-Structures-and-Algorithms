class Solution {
public:
    string truncateSentence(string s, int k) {
        int i;
        for(i=0;k!=0 && i<s.size();i++){
            if(s[i]==' ')
                k--;
        }
        if(i!=s.size())
            s=s.substr(0,i-1);
        return s;
    }
};