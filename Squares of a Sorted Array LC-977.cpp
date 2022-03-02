// First
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// Second
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        int i=0;
        while(i<nums.size() && nums[i]<0){
            nums[i]*=-1;
            i++;
        }
        int j=i-1;
        while(j>=0 && i<nums.size()){
            if(nums[i]<=nums[j]) res.push_back(nums[i]*nums[i++]);
            else res.push_back(nums[j]*nums[j--]);
        }
        while(j>=0){
            res.push_back(nums[j]*nums[j--]);
        }
        while(i<nums.size()){
            res.push_back(nums[i]*nums[i++]);
        }
        return res;
    }
};