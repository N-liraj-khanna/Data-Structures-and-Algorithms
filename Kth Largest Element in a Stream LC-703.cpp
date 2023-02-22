// tc=o(n)
// tc=o(k)
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>size) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


// tc=o(n)
// tc=o(k)
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int _k;
    KthLargest(int k, vector<int>& nums) {
        _k=k;
        sort(nums.begin(),nums.end(), greater<int>());
        for(int i=0;i<k && i<nums.size();i++){
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        if(pq.size()!=_k) pq.push(val);
        else if(val>pq.top()){
            pq.push(val);
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */