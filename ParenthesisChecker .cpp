/*******************Paranthesis Checker*****************/
//OPTIMIZED -> TC => O(N)  SC=>O(N)
bool ispar(string x)
{
    stack<char> stk;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == '{' || x[i] == '[' || x[i] == '(')
            stk.push(x[i]);
        else if (x[i] == '}' || x[i] == ']' || x[i] == ')') {
            if (stk.empty()) return false;
            char c = stk.top();
            if (c == '(' && x[i] == ')') stk.pop();
            else if (c == '[' && x[i] == ']') stk.pop();
            else if (c == '{' && x[i] == '}') stk.pop();
            else return false;
        }
    }
    return stk.empty();
}