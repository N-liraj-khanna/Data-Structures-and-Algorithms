// Tc->O(log(base2)N)
// SC->O(1)
public:
    double myPow(double x, int n) {
        if(x==1 || x==0) return x;
        
        long nn=(long)n;
        double out=1;
        nn=abs(nn);
        while(nn){
            if(nn%2){
                out*=x;
                nn--;
            }else{
                x=x*x;
                nn/=2.0;
            }
        }
        if(n<0) out=1/out;
        return out;
    }
};
// Tc->O(N)
// SC->O(1)
class Solution {
public:
    double myPow(double x, int n) {
        double out=1;
        if(n==0) return out;
        else if(n>0){
            while(n--){
                out*=x;
            }
        }else{
            while(n<0){
                out/=x;
                n++;
            }
        }
        return out;
    }
};