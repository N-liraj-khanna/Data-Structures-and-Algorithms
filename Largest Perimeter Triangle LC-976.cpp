// tc=o(nlogn)
// sc=o(1)
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        long maxi=0;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=2;i--){
            if(nums[i]<nums[i-1]+nums[i-2]){
                return nums[i]+nums[i-1]+nums[i-2];
            }
        }
        return maxi;
    }
};