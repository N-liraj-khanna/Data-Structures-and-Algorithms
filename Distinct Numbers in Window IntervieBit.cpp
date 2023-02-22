// tc=o(n)
// sc=o(B)
vector<int> Solution::dNums(vector<int> &nums, int B) {
    if(B>nums.size()) return {};
    
    unordered_map<int,int> mp;
    for(int i=0;i<B;i++){
        mp[nums[i]]++;
    }
    vector<int> res;
    res.push_back(mp.size());
    
    for(int i=B;i<nums.size();i++){
        mp[nums[i-B]]--;
        if(mp[nums[i-B]]==0) mp.erase(nums[i-B]);
        mp[nums[i]]++;
        res.push_back(mp.size());
    }
    return res;
}
