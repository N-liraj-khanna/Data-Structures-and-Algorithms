/*********INTERLEAVE VALUES OF QUEUE TO FIRST HALF WITH SECOND HALF***********/
//Only one queue used
//OPTIMIZED -> TC => O(N)  SC=>O(N/2)  
queue<int> interleaveQue(queue<int> q) {
    int n = q.size();
    queue<int> que;
    for (int i = 0; i < n / 2; i++) {
        que.push(q.front());
        q.pop();
    } //11 16 12 17 13 18 14 19 15 20 
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            q.push(que.front());
            que.pop();
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }
    return q;
}

//using two queue extra to split in half
//Naive -> TC => O(N)  SC=>O(N)  
queue<int> interleaveQue(queue<int> q) {
    int n = q.size();
    queue<int> q1;
    for (int i = 0; i < n / 2; i++) {
        q1.push(q.front());
        q.pop();
    } 
    queue<int> main;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            main.push(q1.front());
            q1.pop();
        }
        else {
            main.push(q.front());
            q.pop();
        }
    }
    return main;
}
