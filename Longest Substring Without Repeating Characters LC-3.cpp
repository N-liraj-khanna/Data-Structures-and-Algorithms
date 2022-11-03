// Using just integers as index staring (Kadane's/Sliding window)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> map;
        int start=0, end=0, maxi=0;
        int N=s.size();
        
        while(end<N){
            if(map.find(s[end])!=map.end()){
                maxi=max(maxi, end-start);
                while(map[s[end]]!=0){
                    map[s[start++]]=0;
                }
            }
            map[s[end++]]++;
        }
        return max(maxi, end-start);
    }
};


// Using temp staring (Kadane's/Sliding window)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> map;
        int end=0;
        int N=s.size();
        string res="", temp="";
        
        while(end<N){
            
            if(map.find(s[end])!=map.end()){
                res=temp.size()>res.size()?temp:res;
                while(map[s[end]]!=0){
                    map[temp[0]]=0;
                    temp=temp.substr(1);
                }
            }
            map[s[end]]=1;
            temp+=s[end];
            end++;
        }
        return temp.size()>res.size()?temp.size():res.size();
    }
};

// My approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2) return s.size();
        unordered_map<char,int> map;
        int maxi=0;
        string chk="";
        for(int i=0, j=0;i<s.size()&&j<s.size();i++){
            
            if(map.find(s[i])!=map.end()){
                maxi=maxi<chk.size()?chk.size():maxi;
                chk="";
                i=++j;
                map.clear();
            }
            chk+=s[i];
            map[s[i]]++;
        }
    
        maxi=maxi<chk.size()?chk.size(): maxi;
        
        return maxi;
    }
};