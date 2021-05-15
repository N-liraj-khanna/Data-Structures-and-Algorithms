//used a set
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> morseCode = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        int count=0;
        unordered_set<string> checkCode;
        
        for(string word: words){
            string currMorseCode="";
            for(char c: word)
                currMorseCode+=morseCode[c-97];
            checkCode.insert(currMorseCode);
        }
        return checkCode.size();
    }
};
//used a map
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> morseCode = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
            ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
            ".--","-..-","-.--","--.."};
        
        int count=0;
        string currMorseCode="";
        map<string,bool> checkCode;
        
        for(string word: words){
            currMorseCode="";
            for(char c: word)
                currMorseCode+=morseCode[c-97];
            if(!checkCode[currMorseCode])
                checkCode[currMorseCode]=true;
        }
        return checkCode.size();
    }
};