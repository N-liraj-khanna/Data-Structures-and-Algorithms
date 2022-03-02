class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int res=0;
        for(vector<string> it: items){
            if(ruleKey=="type" && ruleValue==it[0]) res++;
            if(ruleKey=="color" && ruleValue==it[1]) res++;
            if(ruleKey=="name" && ruleValue==it[2]) res++;
        }
        return res;
    }
};