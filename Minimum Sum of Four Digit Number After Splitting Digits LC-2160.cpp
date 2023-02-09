// tc=o(nlogn)
// sc=o(n)
class Solution {
public:
    int minimumSum(int num) {
        vector<int> v;
        int maxi=0;
        for(int i=0;i<4;i++){
            v.push_back(num%10);
            num/=10;
        }
        sort(v.begin(),v.end());
        return (v[0]*10+v[2])+(v[1]*10+v[3]);
    }
};