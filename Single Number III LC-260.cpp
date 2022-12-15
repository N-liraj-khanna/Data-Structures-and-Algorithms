// bit manupulation
// tc=> O(N) sc => O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++){
            x=x^nums[i];
        }

        int cnt=0;
        while(x){
            if(x&1) break;
            cnt++;
            x=x>>1;
        }
        
        int x1=0,x2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&(1<<cnt))
                x1=x1^nums[i];
            else
                x2=x2^nums[i];
        }
        return {x1,x2}; 
    }
};