class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        
        int count=0;
        
        int key;
        key = (ruleKey=="type")?0:((ruleKey=="color")?1:2);
        
        for(vector<string>& item: items){
            if(item[key]==ruleValue)
                count++;
        }
        return count;
    }
};