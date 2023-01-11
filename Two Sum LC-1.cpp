// Brute force
// TC=O(N^2)
// SC=O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target) return {i,j};
            }
        }
        return {};
    }
};

// HashMap
// tc=o(n)
// sc=O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            if(map.find(target-nums[i])!=map.end()){
                return {map[target-nums[i]],i};
            }
            map[nums[i]]=i;
        }
        return {};
    }
};

// two pointers if given input is sorted
// tc=o(N)
// sc=o(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]==target){
                return {i,j};
            }else if(nums[i]+nums[j]>target){
                j--;
            }else{
                i++;
            }
        }
        return {};
    }
};

// Two pointers when not sorted
// tc=O(NlogN)
// sc=O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        vector<int> backup,res;
        backup=nums;
        sort(nums.begin(),nums.end());
        while(i<j){
            if(nums[i]+nums[j]==target){
                for(int a=0;a<backup.size();a++){
                    if(nums[i]==backup[a]) res.push_back(a);
                    else if(nums[j]==backup[a]) res.push_back(a);
                    if(res.size()==2) return res;
                }
            }else if(nums[i]+nums[j]>target){
                j--;
            }else{
                i++;
            }
        }
        return res;
    }
};