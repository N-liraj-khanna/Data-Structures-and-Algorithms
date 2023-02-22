// tc=o(max(num of set bits))
// sc=o(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int tot=0;
        while(n){
            n=(n&(n-1));
            tot++;
        }
        return tot;
    }
};

// tc=o(n)
// sc=o(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int tot=0;
        while(n){
            tot=tot+(n&1==1?1:0);
            n=n>>1;
        }
        return tot;
    }
};
// tc=o(n)
// sc=o(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int tot=0;
        while(n){
            tot=tot+n%2;
            n/=2;
        }
        return tot;
    }
};