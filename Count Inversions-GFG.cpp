// TC->O(NlogN)
// SC->O(N)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int merge(long long arr[], long long first, long long mid, long long last){
        
        long long int count=0;
        vector<long long> temp;
        long long i=first, j=mid+1;
        
        while(i<=mid && j<=last){
            if(arr[i]>arr[j]){
                temp.push_back(arr[j++]);
                count=count+(mid-i)+1;
            }else{
                temp.push_back(arr[i++]);
            }
        }
        while(i<=mid){
            temp.push_back(arr[i++]);
        }
        while(j<=last){
            temp.push_back(arr[j++]);
        }
        
        i=0;
        while(first<=last){
            arr[first++]=temp[i++];
        }
        return count;
    }
    
    long long int mergeSort(long long arr[], long long first, long long last){
        long long int count=0;
        if(first<last){
            long long mid=first+(last-first)/2;
            count+=mergeSort(arr,first,mid);
            count+=mergeSort(arr,mid+1,last);
            count+=merge(arr,first,mid,last);
        }
        return count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends