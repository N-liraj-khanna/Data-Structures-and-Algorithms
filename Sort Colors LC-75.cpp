// Dutch National Flag ALgo
// TC => O(N) SC => O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            } 
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }else{
                mid++;
            }
        }
    }
};

// COunting Sort
// TC => O(N) SC => O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r=0,w=0,b=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) r++;
            else if(nums[i]==1) w++;
            else b++;
        }

        for(int i=0;i<nums.size();i++){
            if(r){
                nums[i]=0;
                r--;
            }
            else if(w){
                nums[i]=1;
                w--;
            } 
            else if(b){
                nums[i]=2;
                b--;
            } 
        }
    }
};

// Inbuilt sort method
// TC => O(nlogN) SC=>O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};