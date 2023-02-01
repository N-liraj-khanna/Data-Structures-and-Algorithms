// tc=o(nlog)

int findLess(int row,int t,vector<int>&A){
    int low=0,high=A.size()-1;
    int cnt=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(t>=A[mid]){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int low=INT_MAX, high=INT_MIN;
    int n=A.size(),m=A[0].size();
    int lim=(n*m)/2;
    
    for(int i=0;i<n;i++){
        low=min(low,A[i][0]);
        high=max(high,A[i][m-1]);
    }
    
    while(low<=high){
        int mid=low+(high-low)/2;
        
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=findLess(i,mid,A[i]);
        }
        if(cnt<=lim){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}
