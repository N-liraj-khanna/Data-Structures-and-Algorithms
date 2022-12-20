// Power set Algorithm
// Bit manupulation
// TC=> O(2^n)*O(N) bad algorithm
// SC => O(1)
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