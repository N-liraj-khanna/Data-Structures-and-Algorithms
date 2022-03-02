//No Stack
class Solution {
public:
    int maxDepth(string s) {
        int depth=0,count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                count++;
            else if(s[i]==')')
                depth = max(depth,count--);
        }
        return depth;
    }
};

//using stack
class Solution {
public:
    int maxDepth(string s) {
        int depth=0,count=0;
        stack<char> brackets;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                brackets.push(')');
                count++;
            }else if(s[i]==')'){
                depth = max(depth,count);
                count--;
                brackets.pop();
            }
        }
        return depth;
    }
};