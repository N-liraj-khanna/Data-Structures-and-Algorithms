// tc=o(nlogn)
// sc=o(k)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> res;

        for(int i: nums){
            map[i]++;
        }
        int count=0;
        for(pair<int,int> i: map){
            if(count>=k){
                if(i.second>pq.top().first){
                    pq.pop();
                    pq.push({i.second,i.first});
                }
            }else{
                pq.push({i.second,i.first});
                count++;
            }
        }
        for(int i=0;i<k;i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};