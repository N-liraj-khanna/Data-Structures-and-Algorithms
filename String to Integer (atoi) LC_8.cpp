// tc=o(n)
// sc=o(1)
class Solution {
public:
    int myAtoi(string s) {
        int op=0;
        int start=0,n=s.size();

        while(start<n && s[start]==' ') start++;
        bool sign=false, range=true;;

        if(start<n && s[start]=='-'){
            sign=true;
            start++;
        }else if(start<n && s[start]=='+') start++;

        while(start<n){
            if(s[start]<'0' || s[start]>'9') break;
            long temp=((long)op*10+((long)s[start]-(long)'0'));
            if(temp>INT_MAX){
                op=INT_MAX;
                range=false;
            }else{
                op=temp;
            }
            start++;
        }
        if(sign){
            op=!range?INT_MIN:(-1*op);
        }
        return op;
        
    }
};