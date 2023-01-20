// tc=o(n^2)
// sc=o(n)
class Solution {
public:
    string getPermutation(int n, int k) {
        string in="";
        int fact=1;
        for(int i=1;i<=n;i++){
            in+=to_string(i);
            fact*=i;
        }
        k-=1;

        string out="";
        while(in.size()){
            fact/=in.size();
            out=out+in[k/fact];
            in.erase(in.begin()+k/fact,in.begin()+k/fact+1);
            k%=fact;
        }
        return out;
    }
};

// not recommended at all, waste method
// tc=o(n*n!)+o(n)
// sc=o(n)
class Solution {
public:
    string getPermutation(int n, int k) {
        string res="";
        while(n>0){
            res+=to_string(n);
            n--;
        }
        next_permutation(res.begin(),res.end());
        while(k>1){
            next_permutation(res.begin(),res.end());
            k--;
        }
        return res;
    }
};