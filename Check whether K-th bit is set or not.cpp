// 1
class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        return ((1<<k)&n)==0?false:true;
    }
};

// 2
class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        return (n>>k)&1==1?true:false;
    }
};