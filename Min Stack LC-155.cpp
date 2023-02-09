// tc=o(1)
// sc=o(1)
class MinStack {
public:
    long mini=INT_MAX;
    stack<long> stk;

    MinStack() {}
    
    void push(int val) {
        if(stk.empty()){
            stk.push(val);
            mini=val;
        }else{
            if(mini>val){
                stk.push((long)2*val-mini);
                mini=val;
            }else{
                stk.push(val);
            }
        }
    }
    
    void pop() {
        if(stk.empty()) return;
        if(mini>stk.top()){
            mini=2*mini-stk.top();
        }
        stk.pop();
    }
    
    int top() {
        if(stk.empty()) return -1;
        if(mini>stk.top()) return mini;
        else return stk.top();
    }
    
    int getMin() {
        return mini;
    }
};


// tc=o(1)
// sc=o(n)
class MinStack {
public:
    stack<pair<int,int>> stk;
    MinStack() {}
    
    void push(int val) {
        if(stk.empty()) stk.push({val,val});
        else{
            stk.push({val,min(stk.top().second,val)});
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.empty()?-1:stk.top().first;
    }
    
    int getMin() {
        return stk.empty()?-1:stk.top().second;
    }
};

