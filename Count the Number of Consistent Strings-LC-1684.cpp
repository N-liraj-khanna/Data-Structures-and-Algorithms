//using vector
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int count=0,flag=1;
        vector<bool> allowedChar(26,0);
        
        for(int i = 0; i<allowed.size();i++)
            allowedChar[allowed[i]-97]=true;
        
        for(auto word: words){
            flag=1;
            for(int i=0;i<word.size();i++){
                if(!allowedChar[word[i]-97]){
                    flag=0;
                    break;
                }
            }
            if(flag)
                count++;
        }
        return count;
    }
};
//really slow and space consuming method
//a map and iterating through each word
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int count=0,flag=1;
        map<char,bool> allowedChar;
        
        for(int i = 0; i<allowed.size();i++)
            allowedChar[allowed[i]]=true;
        
        for(auto word: words){
            flag=1;
            for(int i=0;i<word.size();i++){
                if(!allowedChar[word[i]]){
                    flag=0;
                    break;
                }
            }
            if(flag)
                count++;
        }
        return count;
    }
};