// tc=o(n)
// sc=o(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char,char> map={
            {')','('},
            {'}','{'},
            {']','['}
        };
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stk.push(s[i]);
            }else{
                if(stk.empty() || stk.top()!=map[s[i]]) return false;
                else stk.pop();
            }
        }
        return stk.empty();
    }
};