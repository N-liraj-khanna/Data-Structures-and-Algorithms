class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi=0;
        
        for(string s: sentences){
            int m=count(s.begin(), s.end(), ' ')+1;
            maxi=max(maxi, m);
        }
        
        return maxi;
    }
};