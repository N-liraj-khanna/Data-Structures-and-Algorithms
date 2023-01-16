// tc=o(n)
// sc=o(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int f=1,s=1;
        while(s<nums.size()){
            if(nums[f-1]!=nums[s]){
                nums[f++]=nums[s];
            }else{
                s++;
            }
        }
        return f;
    }
};

// without set, just array
// tc=o(N)
// sc=o(k)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> temp={nums[0]};
        for(int i=1,j=0;i<nums.size();i++){
            if(nums[i]!=temp[j]){
                temp.push_back(nums[i]);
                j++;
            } 
        }
        for(int i=0;i<temp.size();i++){
            nums[i]=temp[i];
        }
        return temp.size();
    }
};

// hashset
// tc=o(N)
// sc=o(k)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> set;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }
        int i=0;
        for(int itr: set){
            nums[i]=itr;
            i++;
        }
        return set.size();
    }
};