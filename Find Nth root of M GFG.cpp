// Add bin search thas all
// tc=o(n*log(m))
// sc=o(1)
class Solution{
	public:
	long long pow(int n,int i, int m){
	    long long op=1;
	    while(op<=m && n--){
	        op*=i;
	    }
	    return op;
	}
	int NthRoot(int n, int m)
	{
	    int start=0,end=m;
	    while(start<=end){
	        int mid=(start+end)/2;
	        long long op=pow(n,mid,m);
	        if(op==m) return mid;
	        else if(op>m){
	            end=mid-1;
	        }else{
	            start=mid+1;
	        }
	    }
	    return -1;
	}  
};

// tle
// tc=o(m*n)
// sc=o(1)
class Solution{
	public:
	int pow(int n,int m){
	    int op=1;
	    while(n--){
	        op*=m;
	    }
	    return op;
	}
	int NthRoot(int n, int m)
	{
	    for(int i=0;i<=m;i++){
	        if(pow(n,i)==m) return i;
	    }
	    return -1;
	}  
};