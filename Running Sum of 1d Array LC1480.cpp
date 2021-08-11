//acumulator
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int acc=nums[i];
            nums[i]+=sum;
            sum+=acc;
        }
        return nums;
    }
};
//adding previous val
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        return nums;
    }
};