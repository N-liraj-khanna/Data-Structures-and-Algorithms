// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long start=1, end=n, mid=(start+end)/2;
        while(start<end){
            bool call=isBadVersion(mid);
            if(call && !isBadVersion(mid-1)) return mid;
            else if(call) end=mid-1;
            else start=mid+1;
            mid=(start+end)/2;
        }
        return isBadVersion(start)?start:0;
    }
};