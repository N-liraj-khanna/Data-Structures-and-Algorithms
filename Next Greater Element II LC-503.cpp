// tc=o(2n+2n)
// sc=o(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> stk;
        vector<int> res(n,-1);

        for(int i=2*n-1;i>=0;i--){
            while(!stk.empty() && stk.top()<=nums[i%n]){
                stk.pop();
            }
            if(!stk.empty())
                res[i%n]=stk.top();
            stk.push(nums[i%n]);
        }
        return res;
    }
};