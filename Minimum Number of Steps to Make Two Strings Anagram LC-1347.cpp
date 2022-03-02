//using vector diff approach
class Solution {
public:
    int minSteps(string s, string t) {
        
        if(s==t) return 0;
        
        int count=0;
        vector<int> letters(26,0);
        
        for(char c: s) letters[c-'a']++;
        for(char c: t) letters[c-'a']--;
        //or
         /*for(int i=0;i<s.size();i++){
            letters[s[i]-'a']++;
            letters[t[i]-'a']--;
        } */
        for(int n: letters) if(n>0) count+=n;
        
        return count;
    }
};

//using vector
class Solution {
public:
    int minSteps(string s, string t) {
        
        if(s==t) return 0;
        
        int count=0;
        vector<int> letters(26,0);
        
        for(char c: s) letters[c-'a']++;
        
        for(char c: t) letters[c-'a']>0?letters[c-'a']--:count++;
        
        return count;
    }
};

//Normal map and check if available, if so decrement letter count,else increment count
class Solution {
public:
    int minSteps(string s, string t) {
        
        int count=0;
        unordered_map<char,int> letters;
        
        for(char c: s) letters[c]++;
        
        for(char c: t) letters[c]>0?letters[c]--:count++;
        
        return count;
    }
};