class Solution {
public:
    string restoreString(string s, vector<int>& ind) {
        for(int i=0;i<s.size();){
            swap(s[i], s[ind[i]]);
            swap(ind[i], ind[ind[i]]);
            
            if(i==ind[i]) i++;
        }
        return s;
    }
};