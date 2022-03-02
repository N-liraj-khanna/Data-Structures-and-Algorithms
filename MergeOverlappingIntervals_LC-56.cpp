//Sort and Linear without stack Most Optimized
//TC => O(NlogN)  SC=>O(1)  
vector<vector<int>> merge(vector<vector<int>>& in) {
    vector<vector<int>> res;
    sort(in.begin(), in.end());
    res.push_back(in[0]);
    for (int i = 1; i < in.size(); i++) {
        if (res.back()[1] >= in[i][0])
            res.back()[1] = max(res.back()[1], in[i][1]);
        else
            res.push_back(in[i]);
    }
    return res;
}

//Sort and linear with stack
//TC => O(NlogN)  SC=>O(N)  
vector<vector<int>> merge(vector<vector<int>>& in) {
    vector<vector<int>> res;
    stack<vector<int>> stk;
    sort(in.begin(), in.end());
    stk.push(in[0]);
    int i, j;
    for (i = 1; i < in.size(); i++) {
        if (in[i][0] <= stk.top()[1] && in[i][1] >= stk.top()[0]) {
            vector<int> temp = stk.top();
            stk.pop();
            temp[1] = max(in[i][1],temp[1]);
            stk.push(temp);
        }
        else
            stk.push(in[i]);

    }
    while (!stk.empty()) {
        res.push_back(stk.top());
        stk.pop();
    }
    return res;
}