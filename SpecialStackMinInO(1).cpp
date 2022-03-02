/**********Stack With All Oprations in O(1) With getting the Min value in O(1)********/
//OPTIMIZED -> TC => O(1)  SC=>O(1)  (ALL OPERATIONS)
struct newStack{ 
    stack<int> s; 
    int min; 
  
    void getMin(){ 
        if(s.empty()){ 
            cout<<"Stack is empty\n"; 
        }
        else{
            cout<<"Minimum element : "<<min<<"\n"; 
        }    
    } 
  
    void pop(){ 
        if(s.empty()){ 
            cout<<"Stack is empty\n"; 
            return; 
        } 
  
        cout<<"Popped element : "; 
        int t = s.top(); 
        s.pop(); 
  
        if(t<min){ 
            cout<<min<< "\n"; 
            min = 2*min - t; 
        } 
  
        else{
            cout<<t<< "\n";
        }    
    } 
  
    void push(int x){ 
        if(s.empty()){ 
            min = x; 
            s.push(x); 
            return; 
        } 
  
        if(x < min){ 
            s.push(2*x - min); 
            min = x; 
        } 
  
        else{
           s.push(x);
        }   
    } 
}; 


// Normal two stack Approach
//Naive/Normal -> TC => O(1)  SC=>O(N)  (ALL OPERATIONS)
class MinStack {
public:
    stack<int> stk;
    stack<int> temp;
    MinStack() {
    }
    
    void push(int val) {
        if(stk.empty()) {
            stk.push(val);
            temp.push(val);
        }else{
            if(temp.top()>val){
                temp.push(val);
            }else{
                temp.push(temp.top());
            }
            stk.push(val);
        }
    }
    
    void pop() {
        stk.pop();
        temp.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return temp.top();
    }
};
