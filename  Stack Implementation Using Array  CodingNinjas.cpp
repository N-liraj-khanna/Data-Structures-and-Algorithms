#include <bits/stdc++.h> 
using namespace std;

class Stack {    
public:
    vector<int> stk;
    int topp=-1;

    Stack(int capacity) {
        stk.resize(capacity);
    }

    void push(int num) {
        topp++;
        stk[topp]=num;
    }

    int pop() {
        if(topp==-1) return -1;
        int t=stk[topp];
        topp--;
        return t;
    }
    
    int top() {
        return topp==-1?-1:stk[topp];
    }
    
    int isEmpty() {
        return topp==-1;
    }
    
    int isFull() {
        return topp==stk.size();
    }
    
};