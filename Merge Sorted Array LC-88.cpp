// optimal
// GAP Method
// TC=>O(N*log(base2)N)
// SC=>O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap=ceil((m+n)/2);
        for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
        while(gap>0){
            for(int i=0;i+gap<m+n;i++){
                if(nums1[i]>nums1[i+gap]){
                    swap(nums1[i],nums1[i+gap]);
                }
            }
            if(gap==1) break;
            gap=ceil((float)gap/2);
        }
    }
};
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap=ceil((m+n)/2);
        for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
        while(true){
            for(int i=0;i+gap<m+n;i++){
                if(nums1[i]>nums1[i+gap]){
                    swap(nums1[i],nums1[i+gap]);
                }
            }
            if(gap==1) break;
            gap=ceil((float)gap/2);
        }
    }
};
// Brute force
// Tc=>O((M+N)log(M+N))
// sc=>O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
};

// better
// tc=>O(n)*O(mlogm)
// sc=>O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i,j;
        for(i=0, j=0;i<m && j<n;){
            if(nums1[i]<=nums2[j]){
                i++;
            }else{
                swap(nums1[i++],nums2[j]);
                sort(nums2.begin(),nums2.end());
            }
        }

        while(i<m+n && j<n){
            nums1[i++]=nums2[j++];
        }
    }
};        