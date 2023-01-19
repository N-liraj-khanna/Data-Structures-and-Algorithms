// best approach
// tc=o(2^n*k)
// sc=(2^n*k)
class Solution {
public:
    void solve(int i, vector<int>&  nums, vector<int> temp, vector<vector<int>>& res){
        res.push_back(temp);

        for(int j=i;j<nums.size();j++){
            if(j!=i && nums[j]==nums[j-1]) continue;
            temp.push_back(nums[j]);
            solve(j+1, nums, temp, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;

        sort(nums.begin(),nums.end());
        solve(0,nums, temp, res);
        return res;
    }
};

// bad approach using set
// tc=o(2^n)*o(logn)
// sc=o(2^n)
class Solution {
public:
    void solve(int i, vector<int>  nums, set<vector<int>>& res){
        if(i>=nums.size()){
            res.insert(nums);
            return;
        }
        solve(i+1,nums,res);
        nums.erase(nums.begin()+i,nums.begin()+i+1);
        solve(i,nums,res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(),nums.end());
        solve(0,nums, res);
        return vector<vector<int>>(res.begin(),res.end());
    }
};