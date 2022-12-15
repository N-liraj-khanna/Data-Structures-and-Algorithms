// Using the formulaes of natual sum and sqaure natural sum
// TC => O(N)  SC=>O(1)
// But power could go large, so a downside
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    int s=(n*(n+1))/2;
    int s2=(n*(n+1)*(2*n+1))/6;
    int tot=0,tot2=0;
    for(int i=0;i<n;i++){
        tot+=A[i];
        tot2+=pow(A[i],2);
    }
    
    int op1=s-tot;
    int op2=(s2-tot2)/op1;
    
    int y=(op2-op1)/2;
    int x=op1+y;
    
    return {y,x};
}
