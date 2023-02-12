// tc=o(n)
// sc=o(1)
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int x=0,y=0;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            x+=nums[i];
            while(temp){
                y+=temp%10;
                temp/=10;
            }
        }
        return abs(x-y);
    }
};