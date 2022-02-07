class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& grp) {
        unordered_map<int,vector<int>> m;
        vector<vector<int>> res;

        for(int i=0;i<grp.size();i++){
            m[grp[i]].push_back(i);
        }
            
        for(auto it: m){
            vector<int> temp;
            for(int i: it.second){
                if(it.first==temp.size()){
                    res.push_back(temp);
                    temp.clear();
                }
                temp.push_back(i);
            }
            res.push_back(temp);
        }

        return res;
    }
};