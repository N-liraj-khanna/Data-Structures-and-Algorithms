#1
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> copy(nums);
        sort(copy.begin(), copy.end());
        
        unordered_map<int,int> m;
                
        for(int i=0;i<copy.size();i++){
            if(m.find(copy[i])==m.end())
                m[copy[i]]=i;
        }
        
        for(int i=0;i<nums.size();i++){
            copy[i]=m[nums[i]];
        }
        
        return copy;
    }
};