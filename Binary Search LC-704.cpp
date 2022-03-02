class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1, mid=(start+end)/2;
        
        while(start<end){
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) end=mid-1;
            else start=mid+1;
            mid=(start+end)/2;
        }
        
        return nums[start]==target?start:-1;
    }
};