// The four step process
// TC=3*O(N) SC=O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        
        int ind1=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind1=i;
                break;
            }
        }

        int ind2=0;
        for(int i=n-1;ind1!=-1 && i>=0;i--){
            if(nums[i]>nums[ind1]){
                ind2=i;
                break;
            }
        }

        swap(nums[ind1==-1?0:ind1],nums[ind2]);
        
        reverse(nums.begin()+ind1+1,nums.end());
    }
};

// Same code bit style changed
class Solution {
public:
    void nextPermutation(vector<int>& nums) {        
        int i;
        for(i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]) break;
        }

        if(i>=0){
            int j;
            for(j=nums.size()-1;j>=0;j--){
                if(nums[j]>nums[i]) break;
            }
            swap(nums[i],nums[j]);
        }

        reverse(nums.begin()+i+1,nums.end());
    }
};

// Inbuilt zC++ method
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};