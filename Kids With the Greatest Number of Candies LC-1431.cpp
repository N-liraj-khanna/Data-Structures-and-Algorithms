class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& arr, int extra) {
        vector<bool> res;
        int min=*max_element(arr.begin(), arr.end())-extra;
        
        for(int i=0;i<arr.size();i++)
            res.push_back(arr[i]>=min);
        
        return res;
    }
};