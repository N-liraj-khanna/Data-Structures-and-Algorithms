// 1 method
class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
  
        s1.push(x);
  
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        if(s1.empty()) return -1;
        int t=s1.top();
        s1.pop();
        return t;
    }
    
    int peek() {
        if(s1.empty()) return -1;
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


// 2 method
class MyQueue {
public:
    stack<int> stk1;
    MyQueue() {
        
    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        if(stk1.empty()) return -1;

        stack<int> stk2;
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        int op=stk2.top();
        stk2.pop();
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        return op;
    }
    
    int peek() {
        if(stk1.empty()) return -1;

        stack<int> stk2;
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        int op=stk2.top();
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        return op;
    }
    
    bool empty() {
        return stk1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */