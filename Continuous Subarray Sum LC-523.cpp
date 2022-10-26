// Best Method
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(k==0){
            for(int i=1;i<nums.size();i++){
                if(nums[i]==0 && nums[i-1]==0) return true;
            }
            return false;
        }
        
        unordered_map<int,int> map;
        int prefix=0;
        
        map[0]=-1;
        
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            if(map.find(prefix%k)!=map.end()){
                if((i-map[prefix%k])>1){
                    return true;  
                } 
            }else{
                map[prefix%k]=i;
            }
        }
        return false;
    }
};

// Worst Method
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(k==0) return true;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            for(int j=i+1;j<nums.size();j++){
                n+=nums[j];
                if(n%k==0) return true;
            }
        }
        return false;
    }
};