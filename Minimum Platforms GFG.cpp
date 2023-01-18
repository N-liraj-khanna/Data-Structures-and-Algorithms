// tc=o(nlogn)*2+o(n)
// sc=o(1)
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr+n);
        sort(dep, dep+n);
    	int a=0,d=0;
    	int platforms=0, maxi=0;
    	while(a<n){
    	    if(arr[a]<=dep[d]){
    	        a++;
    	        platforms++;
    	        maxi=max(platforms,maxi);
    	    }else{
    	        d++;
    	        platforms--;
    	    }
    	}
    	return maxi;
    }
};