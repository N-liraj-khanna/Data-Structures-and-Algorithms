// tc=o(n*k)
// sc=o(n)
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        
        int count=1;
        string op=countAndSay(n-1);
        string res="";
        for(int i=1;i<op.size();i++){
            if(op[i]!=op[i-1]){
                res+=(char)(count+'0');
                res+=(char)op[i-1];
                count=0;
            }
            count++;
        }
        res+=(char)(count+'0');
        res+=(char)op[op.size()-1];
        return res;
    }
};