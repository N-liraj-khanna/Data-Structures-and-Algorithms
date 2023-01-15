// tc=o(n^2)+o(nlogn)
// sc=o(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int start=i+1,end=n-1; 
            while(start<end){
                int tot=nums[i]+nums[start]+nums[end];
                if(tot==0){
                    res.push_back({nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                    while(start<n && start>0 && nums[start-1]==nums[start]) start++;
                    while(end>=0 && end<n-1 && nums[end]==nums[end+1]) end--;
                }else if(tot<0){
                    start++;
                }else{
                    end--;
                }
            }
        }
        return res;
    }
};