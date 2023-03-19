// bnary search
// tc=o(NlogN)
// sc=o(N)
class Solution {
public:
    int binarySearch(vector<int>& arr, int l, int r, int x){
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);
            return binarySearch(arr, mid + 1, r, x);
        }
        return l;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        lis.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
            if(lis.back()<nums[i]){
                lis.push_back(nums[i]);
            }else{
                int ind=binarySearch(lis,0,lis.size()-1,nums[i]);
                lis[ind]=nums[i];
            }
        }
        return lis.size();
    }
};

// simple check yet efficient
// tc=o(N^2)
// sc=o(N^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(),1);

        for(int i=nums.size()-2;i>=0;i--){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]<nums[j]){
                    lis[i]=max(lis[i],1+lis[j]);
                }
            }
        }
        int maxi=0;
        for(int i=0;i<lis.size();i++){
            maxi=max(maxi,lis[i]);
        }
        return maxi;
    }
};

// memoization
// tc=o(n^2)
// sc=o(n)
class Solution {
public:
    int dfs(int ind, vector<int>& nums, unordered_map<int,int>& dp){
        
        if(ind==nums.size()) return 0;
        if(dp.find(ind)!=dp.end()) return dp[ind];

        int maxi=0;
        for(int i=ind+1;i<nums.size();i++){
            if(nums[i]>nums[ind]){
                dp[i]=dfs(i,nums,dp);
                maxi=max(maxi,dp[i]);
            }
        }
        return maxi+1;
    }
    int lengthOfLIS(vector<int>& nums) {
        unordered_map<int,int> dp;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(dfs(i,nums,dp),maxi);
        }
        return maxi;
    }
};