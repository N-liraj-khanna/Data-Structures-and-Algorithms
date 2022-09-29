class MinStack {
public:
    vector<pair<int,int>> stk;
    int up=-1;
    MinStack() {}
    
    void push(int val) {
        if(stk.empty()){
            stk.push_back({val, val});
        }else{
            stk.push_back({val,min(stk[up].second, val)});
        }
        up++;

    }
    
    void pop() {
        stk.pop_back();
        up--;
    }
    
    int top() {
        return stk[up].first;
    }
    
    int getMin() {
        return stk[up].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */