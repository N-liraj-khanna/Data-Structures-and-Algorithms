// tc=O(3n)=O(n)+o(n)+o(n) 
//3n=>pushing to hash // iterating to hash 
//maxiteratio inside the while will sum up to n as a whole think aobout it
// sc=o(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi=0;
        unordered_set<int> set;
        for(int i: nums) set.insert(i);

        for(int i: set){
            if(set.find(i-1)==set.end()){
                int itr=0;
                while(set.find(i+itr)!=set.end()){
                    itr++;
                }
                maxi=max(maxi,itr);
            }
        }

        return maxi;
    }
};

// tc=o(n*(longest sequence length))
// sc=o(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> map;
        int maxi=0;

        for(int i=0;i<nums.size();i++){
            map[nums[i]]=1;
        }
        for(auto i: map){
            int itr=1;
            while(map.find(i.first+itr)!=map.end()){
                map[i.first]++;
                itr++;
            }
            maxi=max(map[i.first],maxi);
        }
        return maxi;
    }
};