// Sorting and hashing
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map; 
        
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(), temp.end());
            map[temp].push_back(strs[i]);
        }
        
        vector<vector<string>> res(map.size());
        int idx=0;
        for(auto a: map){
            for(auto b: a.second)
                res[idx].push_back(b);
            idx++;
        }
        return res;
    }
};