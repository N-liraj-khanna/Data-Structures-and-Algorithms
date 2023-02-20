class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char,int> map;
        for(char i: m){
            map[i]++;
        }
        for(char i: r){
            if(map.find(i)==map.end() || map[i]==0) return false;
            map[i]--;
        }
        return true;
    }
};