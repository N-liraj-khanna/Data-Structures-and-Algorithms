
/*************Max Sliding WIndow Optimal Approach*********************/
//TC => O(N)
//SC => O(k)
vector <int> max_of_subarrays(int* nums, int n, int k) {
   deque <int> dq;
   vector<int> res(n - k + 1);
   for (int i = 0; i < n; i++) {
       if (!dq.empty() && dq.front() == i - k)
           dq.pop_front();
       while (!dq.empty() && nums[dq.back()] < nums[i])
           dq.pop_back();
       dq.push_back(i);
       if (i >= k - 1)
           res[i - k + 1] = nums[dq.front()];
   }
   return res;
}


/**************Sliding WIndow Naive Approach******************/
// TC => O(N*K)
//SC => O(k)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
   deque<int> dq;
   vector<int> v;
   int max = nums[0];
   for (int i = 0; i < k; i++) {
       if (nums[i] > max)
           max = nums[i];
       dq.push_back(nums[i]);
   }
   for (int i = k; i < nums.size(); i++) {

       v.push_back(max);
       dq.pop_front();
       dq.push_back(nums[i]);
       for (auto i : dq) {
           if (max < i)max = i;
       }
       v.push_back(max);

   }
   return v;
}