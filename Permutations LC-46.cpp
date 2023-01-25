// Less space
// tc=o(fact(n))*o(n)
// sc=o(n)
class Solution {
public:
    void solve(int ind,vector<int>& nums, vector<vector<int>>& res){
        if(ind==nums.size()){
            res.push_back(nums);
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            solve(ind+1,nums,res);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(0, nums,res);
        return res;
    }
};


// extra space complexity method
// tc=o(fact(n))*o(n)
// sc=o(n)+o(n)+o(n)
class Solution {
public:
    void solve(vector<int>& nums, vector<int>& temp, vector<int>& freq, vector<vector<int>>& res){
        if(temp.size()==nums.size()){
            res.push_back(temp);
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                temp.push_back(nums[i]);
                freq[i]=1;
                solve(nums,temp,freq,res);
                temp.pop_back();
                freq[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> freq(nums.size(),0);
        vector<vector<int>> res;
        vector<int> temp;
        solve(nums,temp,freq,res);
        return res;
    }
};