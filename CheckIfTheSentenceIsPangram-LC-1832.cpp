//using vector/array
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> alpha(26,0);
        for(int i=0;i<sentence.size();i++){
            alpha[sentence[i]-97]++;
        }
        for(int i=0;i<26;i++){
            if(alpha[i]==0)
                return false;
        }
        return true;
    }
};
//Using map
class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,int> alpha;
        for(int i=0;i<sentence.size();i++){
            alpha[sentence[i]]++;
        }
        for(int i=97;i<=122;i++){
            if(alpha[i]==0)
                return false;
        }
        return true;
    }
};