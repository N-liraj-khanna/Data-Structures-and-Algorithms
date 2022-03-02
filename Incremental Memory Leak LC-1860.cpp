//just subract every second(i.e., 'i' in here) with the greatest value of memory
//availabe, until i becomes greater than both, then the ith is second, m1 and m2 are the left memory
//TC => O(m1+m2) SC=>O(1) Approx.
class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
        vector<int> res;
        
        int i;
        for(i=1;i<=m1 || i<= m2;i++)
            if(m1>=m2)
                m1-=i;
            else
                m2-=i;
        res.push_back(i);
        res.push_back(m1);
        res.push_back(m2);
        return res;
    }
};