/****************A Stack Using Deque**************/
/* The structure of the class is
class QueueStack{
private:
    deque<int> q1;
    deque<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
//OPTIMIZED -> 
//push() operation -> TC => O(N)  SC=>O(1)
//pop() operation -> TC => O(1)  SC=>O(1)
void push(int x){
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    q1.push(x);
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();       
    }
}
int pop(){
    int val = q1.front();
    q1.pop_front();
    return val;
}