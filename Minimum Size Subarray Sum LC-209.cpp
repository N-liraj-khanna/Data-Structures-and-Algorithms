class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int N=nums.size();
        int start=0,end=0;
        int sum=0, length=N+1;
        
        while(start!=N){
            if(sum>=target){
                length=min(end-start, length);
                sum-=nums[start++];
            }else if(end==N && sum<target){
                break;
            }else if(end<N){
                sum+=nums[end++];
            }
        }
        
        return length==N+1?0:length;
    }
};