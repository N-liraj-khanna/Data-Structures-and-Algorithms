// Best apporach 
// bit manipulation
// TC=>O(N) SC=>O(1)
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int* out=new int[2];
        int x=0;
        for(int i=0;i<n;i++){
            x^=arr[i];
            x^=(i+1);
        }

        int x0=0,x1=0;
        int lastbit=(x&~(x-1));
        
        for(int i=0;i<n;i++){
            if((arr[i]&lastbit)){
                x0^=arr[i];
            }else{
                x1^=arr[i];
            }
            if(((i+1)&lastbit)){
                x0^=(i+1);
            }else{
                x1^=(i+1);
            }
        }
        
        for(int i=0;i<n;i++){
            if(x0==arr[i]) break;
            if(x1==arr[i]){
                swap(x0,x1);
                break;
            }
        }
        
        out[0]=x0;
        out[1]=x1;
        return out;
    }
};

// Using the sign trick modifying input array
// TC=>O(N) SC => O(1)
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int* out = new int[2];
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1]<0){
                out[0]=abs(arr[i]);
            }else{
                arr[abs(arr[i])-1]*=-1;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0) out[1]=i+1;
        }
        return out;
    }
};


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
