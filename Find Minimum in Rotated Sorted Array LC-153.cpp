// tc=o(logn)
// sc=o(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0]<nums[nums.size()-1]) return nums[0];
        
        int start=0,end=nums.size()-1;
        while(start<end){
            int mid=start+(end-start)/2;
            if(mid>0 && nums[mid]<nums[mid-1]){
                return nums[mid];
            }else if(nums[start]<nums[mid]){
                start=mid;
            }else{
                end=mid-1;
            }
        }
        return nums[nums.size()>1?start+1:0];
    }
};