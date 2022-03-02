// Normal stuff(giv em' a read!!)
class Solution {
public:
    string breakPalindrome(string p) {
        int N=p.size();
        if(N==1)
            return "";

        string temp=p;
        
        for(int i=0;i<N;i++)
            if(p[i]!='a' && !(N%2==1 && i==N/2)){  
                p[i]='a';
                break;
            }

        if(temp==p)
            p[N-1]=p[N-1]+1;
        return p;
    }
};