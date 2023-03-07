class Solution {
public:
    int reverse(int x) {
        stack<int> stk;
        while(x){
            stk.push(x%10);
            x/=10;
        }
        int tens=0;
        while(!stk.empty()){
            if(pow(10,tens)*stk.top()+x > INT_MAX || pow(10,tens)*stk.top()+x < INT_MIN) 
                return 0;
            x=pow(10,tens)*stk.top()+x;
            stk.pop();
            tens++;
        }
        return  x;
    }
};
