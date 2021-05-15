/***********************REVERSE POLISH***************************************/
//Using If Else Statement
//OPTIMIZED => TC => O(N)  SC=>O(N)  
int evalRPN(vector<string>& tokens) {
    int eval = 0, op1, op2;
    stack<int> stk;
    for (int i = 0; i < tokens.size(); i++) {
        int c = tokens[i][1]=='\0'?tokens[i][0]:'\0';
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            op1 = stk.top();
            stk.pop();
            op2 = stk.top();
            stk.pop();
        }
        if (tokens[i].size()<2 && c >= 48 && c <= 57) {
            stk.push(c - '0');
        }
        else if (c == '+') {
            stk.push((op1 + op2));
        }
        else if (c == '-') {
            stk.push((op2 - op1));
        }
        else if (c == '*') {
            stk.push((op1 * op2));
        }
        else if (c == '/') {
            stk.push((op2 / op1));
        }
        else {
            int val = 0,check=0; //INSTEAD OF STOI, TO CONVERT TWO DIGIT STRING AS CHARACTER 
            for (int k = 0; k < tokens[i].size(); k++) {
                if (tokens[i][k] == '-') {
                    check = 1; continue;;
                }
                val *= 10;
                val += tokens[i][k] - '0';
            }
            if (check) val *= -1;
            stk.push(val);
        }
    }
    return stk.top();
}

//Using Switch Case
//OPTIMIZED => TC => O(N)  SC=>O(N)  
int evalRPN(vector<string>& tokens) {
    int eval = 0, op1, op2;
    stack<int> stk;
    for (int i = 0; i < tokens.size(); i++) {
        int c = tokens[i][1]=='\0'?tokens[i][0]:'\0';
        if (tokens[i].size()<2 && c >= 48 && c <= 57) {
            stk.push(c - '0');
        }else if (c == '+' || c == '-' || c == '*' || c == '/') {
            op1 = stk.top();
            stk.pop();
            op2 = stk.top();
            stk.pop();
            switch (c) {
            case '+': 
                stk.push((op1 + op2)); break;
            case '-': 
                stk.push((op2 - op1)); break;
            case '*': 
                stk.push((op1 * op2)); break;
            case '/': 
                stk.push((op2 / op1)); break;
            }
        }else {
            int val = 0,check=0;    //INSTEAD OF STOI, TO CONVERT TWO DIGIT STRING AS CHARACTER 
            for (int k = 0; k < tokens[i].size(); k++) {
                if (tokens[i][k] == '-') {
                    check = 1; continue;;
                }
                val *= 10;
                val += tokens[i][k] - '0';
            }
            if (check) val *= -1;
            stk.push(val);
        }
    }
    return stk.top();
}
