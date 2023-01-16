// cleaner approach
// tc=o(n)
// sc=o(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0,start=0;
        for(int i=0;i<=nums.size();i++){
            if(i==nums.size()||nums[i]==0){
                maxi=max(maxi,i-start);
                start=i+1;
            }
        }
        return maxi;
    }
};

// Sliding Window/Kadane's Approach
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int start=0, end=0, maxi=0;
        int N=nums.size();
        
        while(end<N){
            if(nums[end]==0){
                maxi=max(end-start, maxi);
                while(++end<N && nums[end]==0){}
                start=end;
            }else
                end++;
        }
        return max(maxi, end-start);
    }
};

//Normal Approach
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0, temp=0;
        int N=nums.size();
        
        for(int e: nums){
            temp+=e;
            if(e==0)
                temp=0;
            maxi=max(temp,maxi);
        }
        return maxi;
    }
};
//Similar to above soln
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0, temp=0;
        for(int e: nums)
            maxi=max({maxi, temp=e==0?0:temp+1});
        return maxi;
    }
};