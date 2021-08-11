class Solution {
public:
    vector<int> decode(vector<int>& enc, int first) {
        vector<int> res={first};
        int acc;
        for(int i=0;i<enc.size();i++){
            res.push_back(enc[i]^res[i]);
        }
        
        return res;
    }
};