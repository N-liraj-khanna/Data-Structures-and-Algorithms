// Kadane's Algo, Most Optimal
// TC=O(N) SC =>O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxi=nums[0];

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        return maxi;
    }
};

// Decent approach Quadratic TC
// TC=> O(N^2) SC=O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                maxi=max(maxi,sum);
            }
        }

        return maxi;
    }
};