#1
class Solution {
public:
    int fact(int n){
        int f=0;
        for(int i=0;i<n;i++) f+=i;
        return f;
    }
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int res=0;
        for(pair<int,int> i: m){
            res+=fact(i.second);
        }
        return res;
    }
};

#2
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int res=0;
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++){
            res+=m[nums[i]]++;
        }
        return res;
    }
};