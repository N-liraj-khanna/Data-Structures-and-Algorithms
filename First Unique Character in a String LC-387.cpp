// 1
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26,0);
        for(auto i: s) v[i-'a']++;
        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a']==1) return i;
        }
        return -1;
    }
};
// 2
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> map;
        for(auto i: s) map[i]++;
        for(int i=0;i<s.size();i++){
            if(map[s[i]]==1) return i;
        }
        return -1;
    }
};
