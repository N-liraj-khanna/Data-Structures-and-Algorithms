// Most Optimal
// TC => O(N) + O(N) SC=>O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0;
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        fast=0;
        while(nums[fast]!=nums[slow]){
            slow=nums[slow];
            fast=nums[fast];
        }
        return nums[fast];
    }
};

// #  Hasing solution also possible do on own so similar
// #  sorting solution
// TC => O(NlogN) + O(N) SC=>O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) return nums[i];
        }
        return 0;
    }
};

