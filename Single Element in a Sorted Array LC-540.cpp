// tc=o(logn)
// sc=o(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mid==nums.size()-1) break;
            if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]!=nums[mid+1])){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return nums[start];
    }
};