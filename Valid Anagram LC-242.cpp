// tc=o(n+n)
// sc=o(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map;
        int n=s.size(),m=t.size();
        for(int i=0;i<max(n,m);i++){
            if(i<n) map[s[i]]++;
            if(i<m) map[t[i]]--;
        }
        for(auto i: map){
            if(i.second) return false;
        }

        return true;
    }
};
// tc=o(n+n)
// sc=o(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            if(map.find(t[i])==map.end()){
                return false;
            }
            map[t[i]]--;
            if(map[t[i]]==0) map.erase(t[i]);
        }

        return map.empty();
    }
};

// tc=o(nlogn)+o(nlogn)+o(n)
// sc=o(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};