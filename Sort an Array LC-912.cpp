// Merge Sort
class Solution {
public:
    void merge(vector<int>& nums, int first_start, int first_end, int second_start, int second_end){
        
        int start=first_start;
        vector<int> out;

        while(first_start<=first_end && second_start<=second_end){
            if(nums[first_start]<=nums[second_start]){
                out.push_back(nums[first_start++]);
            }else{
                out.push_back(nums[second_start++]);
            }
        }
        while(first_start<=first_end){
            out.push_back(nums[first_start++]);
        }
        while(second_start<=second_end){
            out.push_back(nums[second_start++]);
        }
        
        for(int i=0;start<=second_end;i++){
            nums[start++]=out[i];
        }
    }
    void mergeSort(vector<int>& nums, int first, int last){
        if(first<last){
            int mid=first+(last-first)/2;
            mergeSort(nums,first,mid);
            mergeSort(nums,mid+1,last);
            merge(nums,first, mid, mid+1, last);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};