// Moore's voting algorithm
// TC->O(N)
// SC->O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,ele=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                ele=nums[i];
                cnt++;
            }else if(ele==nums[i]){
                cnt++;
            }else{
                cnt--;
            }
        }
        return ele;
    }
};