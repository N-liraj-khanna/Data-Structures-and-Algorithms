// tc=o(log(n+m))
// sc=o(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        if(m>n) {
            swap(nums1,nums2);
            swap(m,n);
        }

        int start=0, end=m;
        int half=(n+m+1)/2;

        while(start<=end){
            int m1=(start+end)>>1;
            int m2=half-m1;
            
            int lA = m1<=0 ? INT_MIN:nums1[m1-1];
            int lB = m2<=0 ? INT_MIN:nums2[m2-1];
            
            int rA = m1>=m ? INT_MAX:nums1[m1];
            int rB = m2>=n ? INT_MAX:nums2[m2];
            
            if(lA<=rB && lB<=rA){
                if((n+m)%2){
                    return max(lA,lB);
                }else{
                    return (max(lA,lB)+min(rA,rB))/2.0;
                }
            }else if(lA>rB){
                end=m1-1;
            }else{
                start=m1+1;
            }
        }
        return 0.0;
    }
};