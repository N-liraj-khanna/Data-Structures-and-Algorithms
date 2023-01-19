// Best algo
// tc=o(2^n)
// sc=o(2^n)
class Solution {
public:
    void solve(int i, vector<int>  nums, vector<vector<int>>& res){
        if(i>=nums.size()){
            res.push_back(nums);
            return;
        }
        solve(i+1,nums,res);
        nums.erase(nums.begin()+i,nums.begin()+i+1);
        solve(i,nums,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        solve(0,nums, res);
        return res;
    }
};

// Power set Algorithm
// Bit manupulation
// TC=> O(2^n)*O(N) bad algorithm
// SC => O(2^n)
// only applicable less 16 and not great  than 30
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> out;
         for(int i=0;i<=(1<<n)-1;i++){
             vector<int> in={};
            for(int j=0;j<n;j++){
                if((i&(1<<j))!=0){
                    cout<<j<<" ";
                    in.push_back(nums[j]);
                }
            }
            out.push_back(in);
        }
        return out;
    }
};