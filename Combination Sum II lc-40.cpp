// tc=o(2^n*k)
// sc=o(k*x)
class Solution {
public:
    void solve(int sum, int ind, int t, vector<int> temp, vector<int>& nums, vector<vector<int>>& res){
        if(sum==t){
            res.push_back(temp);
            return;
        } 
        if(sum>t) return;
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(sum+nums[i], i+1,t,temp,nums,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int t) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(0, 0,t,temp,nums,res);
        return res;
    }
};