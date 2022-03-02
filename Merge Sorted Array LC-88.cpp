class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        
        int i=0, j=0;
        
        while(i<(m+n) && j<n){
            if(i>=m){
                a[i++]=b[j++];
            }
            else if(a[i]<=b[j]){
                i++;
            }else if(a[i]>b[j]){
                swap(a[i], b[j]);
                sort(b.begin(), b.end());
            }
        }
    }
};