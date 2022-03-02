/*******************Merge K Sorted Array -> Most Optimal*************************/
// Note=> Even Works with Arrays of Different Size
// TC => O(N*K*logK) SC => O(K)
struct HeapVal {
   int val;
   pair<int, int> idx;
   HeapVal(int value, pair<int, int> index) {
       val = value;
       idx = index;
   }
};
struct CompareVal {
   bool operator()(HeapVal const& val1, HeapVal const& val2) {
       return val1.val > val2.val;
   }
};
vector<int> mergeKArrays(vector<vector<int>> a,int k) {
   priority_queue<HeapVal, vector<HeapVal>,CompareVal> pq;
   vector<int> v;
       for (int j = 0; j <a.size(); j++) {
           pair<int, int> pIdx = {j,1};
           pq.push(HeapVal(a[j][0], pIdx));
       }
   while (!pq.empty()) {
       v.push_back(pq.top().val);
       int x = pq.top().idx.first;
       int y = pq.top().idx.second;
       pq.pop();
       if (y < a[x].size()) {
           pair<int, int> pushPair = { x,y + 1 };
           pq.push(HeapVal(a[x][y], pushPair));
       }
   }
   return v;
}

/****************Merge K Sorted Naive Approach************/
//TC => O(N*K*log(N*K))   SC=>O(N*K), Where N is the size of each arrays/vector(approx.)
vector<int> mergeKArrays(vector<vector<int>> a, int k){
   vector<int> v(a[0]);
   for (int i = 1; i < k; i++) {
       v.insert(v.end(), a[i].begin(), a[i].end());
   }
   sort(v.begin(), v.end());
   return v;
}