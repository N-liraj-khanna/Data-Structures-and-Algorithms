// two ptr apporahc more intuitive to avoid
// tc=o(n)
// sc=o(1)
class Solution {
public:
    int trap(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int lmax=0,rmax=0;
        int res=0;
        while(l<r){
            if(nums[l]<=nums[r]){
                if(lmax<=nums[l]) lmax=nums[l];
                else res+=lmax-nums[l];
                l++;
            }else{
                if(rmax<=nums[r]) rmax=nums[r];
                else res+=rmax-nums[r];
                r--;
            }
        }
        return res;
    }
};

// prefix sum
// tc=o(n)
// sc=o(n)
class Solution {
public:
    int trap(vector<int>& nums) {
        vector<int> prefix(nums.size(),0);
        vector<int> suffix(nums.size(),0);
        int maxi=-1, res=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            prefix[i]=maxi;
        }
        maxi=-1;
        for(int i=nums.size()-1;i>=0;i--){
            maxi=max(maxi,nums[i]);
            suffix[i]=maxi;
        }

        for(int i=0;i<nums.size();i++){
            res=res+(min(prefix[i],suffix[i])-nums[i]);
        }
        return res;
    }
};