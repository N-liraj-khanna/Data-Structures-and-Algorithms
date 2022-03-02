//Sum of N natual numbers approach
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> map;
        
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                map[nums[i]*nums[j]]++;
            }
        }
        int res=0;

        for(auto i: map){
            int n=i.second-1;
            res+=((n*(n+1))/2)*8;    
        }
        return res;
    }
};