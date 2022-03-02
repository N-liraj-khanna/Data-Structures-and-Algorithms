class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& ind) {
        int n=nums.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            res.insert(res.begin()+ind[i], nums[i]);
        }
        return res;
    }
};