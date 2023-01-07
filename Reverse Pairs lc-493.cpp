// TC ->O(2NlogN)
// SC->O(logN)

class Solution {
public:
    int merge(int start, int mid, int end, vector<int> &nums){
        int count=0;
        int i,j;
        for(i=start, j=mid+1;i<=mid;i++){
            while(j<=end && nums[i]>2LL*nums[j]){
                j++;
            }
            count+=(j-(mid+1));
        }
        vector<int> temp;
        for(i=start, j=mid+1;i<=mid && j<=end;){
            if(nums[i]<=nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while(i<=mid) temp.push_back(nums[i++]);
        while(j<=end) temp.push_back(nums[j++]);

        for(i=start;i<=end;i++){
            nums[i]=temp[i-start];
        }
        return count;
    }
    int mergeSort(int first, int last, vector<int>& nums){
        int count=0;
        if(first<last){
            int mid=first+(last-first)/2;
            count=mergeSort(first, mid, nums)+mergeSort(mid+1, last, nums);
            count+=merge(first, mid, last, nums);
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(0,nums.size()-1,nums);
    }
};

// TC ->O(N^2)
// SC->O(1)

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int out=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(abs(nums[i])%2==1 && nums[i]/2>=nums[j]) out++;
                else if(abs(nums[i])%2==0 && nums[i]/2>nums[j]) out++;
            }
        }
        return out;
    }
};