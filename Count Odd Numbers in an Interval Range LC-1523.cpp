// tc=o(1)
// sc=o(1)
class Solution {
public:
    int countOdds(int low, int high) {
        return (low%2==0 && high%2==0) ? ((high-low)/2) : ((high-low)/2+1) ;
    }
};