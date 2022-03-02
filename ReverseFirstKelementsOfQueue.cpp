/*******************QUEUE REVERSAL FOR FIRST K ELEMENTS*****************/

//OPTIMIZED -> TC => O(N)  SC=>O(1)
//No extra space except stack
queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> stk;
    for(int i=0;i<k;i++){
        stk.push(q.front());
        q.pop();
    }
    while(!stk.empty()){
        q.push(stk.top());
        stk.pop();
    }
    for(int i=0;i<q.size()-k;i++){
        q.push(q.front());
        q.pop();
    }
    return q;
}

//Nomral -> TC => O(N)  SC=>O(N)
//Uses extra queue including stack
queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> stk;
    queue<int> que;
    for(int i=0;i<k;i++){
        stk.push(q.front());
        q.pop();
    }
    while(!stk.empty()){
        que.push(stk.top());
        stk.pop();
    }
    while(!q.empty()){
        que.push(q.front());
        q.pop();
    }
    return que;
}
