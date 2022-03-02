/*******************QUEUE USING TWO STACKS*****************/
//OPTIMIZED -> 
//For push -> TC => O(N) SC=>O(1)
//For POP -> TC => O(1) SC=>O(1)
// Note => Vice Versa can also be done similarly

/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
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

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s1.empty()) return -1;
        int val = s1.top();
        s1.pop();
        return val;
}
