class Solution
{
public:
    int setKthBit(int N, int K)
    {
        return ((1<<K)|N);
    }
    
};