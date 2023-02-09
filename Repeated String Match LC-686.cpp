// inbuilt fucntion
// tc=o(n)
// sc=o(1)
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int res=1;
        string temp=a;
        while(a.find(b)==string::npos && a.size()<b.size()+temp.size()){
            a+=temp;
            res++;
        }
        return a.find(b)==string::npos?-1:res;
    }
};