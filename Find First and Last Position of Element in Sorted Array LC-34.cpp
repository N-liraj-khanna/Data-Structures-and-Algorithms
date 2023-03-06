class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                first=i;
                while(i<nums.size() && nums[i]==target){
                    i++;
                }
                return {first,i-1};
            }
        }
        return {-1,-1};
    }
};