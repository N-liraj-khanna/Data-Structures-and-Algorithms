// Time Complexity : log(min(m,n)) 
// Space Complexity: O(1)
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k){
        if(n>m){
            swap(arr1,arr2);
            swap(n,m);
        }
        int start=max(0,k-m),end=min(k,n);
        while(start<=end){
            int m1=start+(end-start)/2;
            int m2=k-m1;
            
            int l1 = m1<=0?INT_MIN:arr1[m1-1];
            int l2 = m2<=0?INT_MIN:arr2[m2-1];
            
            int r1 = m1>=n?INT_MAX:arr1[m1];
            int r2 = m2>=m?INT_MAX:arr2[m2];
            
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }else if(l1>r2){
                end=m1-1;
            }else{
                start=m1+1;
            }
        }
        return 0.0;
    }
};