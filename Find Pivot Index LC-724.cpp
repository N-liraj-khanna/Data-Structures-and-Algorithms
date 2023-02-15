// tc=o(n)
// sc=o(1)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix;
        int sum=nums[0], curr=0;

        prefix.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
            prefix.push_back(prefix[i-1]+nums[i]);
            sum+=nums[i];
        }
        
        for(int i=0;i<prefix.size();i++){
            if(curr==sum-nums[i]-curr) return i;
            curr=prefix[i];
        }
        return -1;
    }
};