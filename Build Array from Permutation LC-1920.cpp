//create new array
class Solution {
 public:
  vector<int> buildArray(vector<int>& nums) {
    vector<int> res(nums.size());

    for (int i = 0; i < nums.size(); i++) {
      res[i] = nums[nums[i]];
    }

    return res;
  }
};

//Using formula, TC->O(2n), SC->O(1)
class Solution {
 public:
  vector<int> buildArray(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      nums[i] = nums[i] + n * (nums[nums[i]] % n);
    }

    for (int i = 0; i < n; i++) {
      nums[i] = nums[i] / n;
    }

    return nums;
  }
};