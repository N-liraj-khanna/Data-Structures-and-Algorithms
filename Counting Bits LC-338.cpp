class Solution {
public:
    int count(int n){
        int c=0;
        while(n>0){
            c+=n%2;
            n/=2;
        }
        return c;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            res.push_back(count(i));
        }
        return res;
    }
};