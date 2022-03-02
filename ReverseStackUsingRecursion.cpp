/***************************STACK REVERSAL***************************/
//With No DS, Only Pure Recursion
//Normal Recursion -> TC => O(N^2)  SC=>O(1)
void atBottom(stack<int>& stk, int x) {
    if (stk.empty())
        stk.push(x);
    else {
        int val = stk.top();
        stk.pop();
        atBottom(stk, x);
        stk.push(val);
    }
}

void revRecursion(stack<int>& stk) {
    if (stk.empty())
        return;
    int val = stk.top();
    stk.pop();
    revRecursion(stk);
    atBottom(stk,val);
}

//With Queue
//OPTIMIZED -> TC => O(N)  SC=>O(N)
void revRecursion(stack<int>& stk,queue<int>& helper) {
    if (stk.empty())
        return;
    helper.push(stk.top());
    stk.pop();
    revRecursion(stk, helper);
    stk.push(helper.front());
    helper.pop();
}