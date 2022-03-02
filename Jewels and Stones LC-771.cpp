class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<int,int> m;
        int res=0;
        
        for(int i=0;i<jewels.size();i++){
            m[jewels[i]]++;
        }
        
        for(int i=0;i<stones.size();i++){
            if(m.find(stones[i])!=m.end())
                res++;
        }
        return res;
    }
};