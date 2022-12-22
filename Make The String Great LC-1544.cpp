// Iterative Method
// TC=>O(N) SC=>O(1)
class Solution {
public:
    string makeGood(string s) {
        for(int i=1;i<s.size();){
            if(abs(s[i]-s[i-1])==32){
                int j=i-1;
                int count=0;
                while(j>=0 && i<s.size() && abs(s[i]-s[j])==32){
                    i++;
                    j--;
                    count++;
                }
                s=s.substr(0,j+1)+s.substr(i,s.size());
                i-=(count*2-1);
            }else{
                i++;
            }
        }
        return s;
    }
};

// Stack method
// TC=>O(N) SC=>O(N)
class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        stk.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(!stk.empty() && abs(s[i]-stk.top())==32) stk.pop();
            else stk.push(s[i]);
        }
        string out="";
        while(!stk.empty()){
            out.push_back(stk.top());
            stk.pop();
        }
        reverse(out.begin(),out.end());
        return out;
    }
};