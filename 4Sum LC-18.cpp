// tc=O(NlogN)+O(N^3)
// sc=O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>> res;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long tgt=target-((long)nums[i]+(long)nums[j]);
                int start=j+1,end=n-1;
                while(start<end){
                    if(tgt==((long)nums[start]+(long)nums[end])){
                        res.insert({nums[i],nums[j],nums[start],nums[end]});
                        start++;
                        end--;
                    }else if(tgt<((long)nums[start]+(long)nums[end])){
                        end--;
                    }else{
                        start++;
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(),res.end());
    }
};

// tc=O(N^3logN)+nlogn
// SC=o(1)
class Solution {
public:
    int binSearch(int start, int end, long target, vector<int>& nums){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return -1;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>> res;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    long tgt=(long)target-((long)nums[i]+(long)nums[j]+(long)nums[k]);
                    int l=binSearch(k+1,n-1,tgt, nums);
                    if(l!=-1){
                        res.insert({nums[i],nums[j],nums[k],nums[l]});
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(),res.end());
    }
};