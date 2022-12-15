// Bit manupulation
// tc=> O(N) sc=> O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int _xor=0;
        for(int i=0;i<nums.size();i++){
            _xor=_xor^nums[i];
        }
        return _xor;
    }
};