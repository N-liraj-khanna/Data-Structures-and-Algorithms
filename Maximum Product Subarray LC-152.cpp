// tc=o(N)
// sc=o(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int maxi=nums[0], mini=nums[0];

        for(int i=1;i<nums.size();i++){
            int tmp=maxi*nums[i];
            maxi=max(nums[i],max(tmp,mini*nums[i]));
            mini=min(nums[i],min(tmp,mini*nums[i]));
            res=max(res,maxi);
        }
        return res;
    }
};