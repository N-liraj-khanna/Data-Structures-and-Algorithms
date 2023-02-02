// tc=o(nlogn)
// sc=o(1)

bool check(int val, vector<int>& arr, int t){
    int count = 0;
    int tot = 0;
    for (int i: arr) {
        if(tot + i > val) {
            count++;
            tot = i;
            if (tot > val) return false;
        }else
        tot += i;
    }
    if(count >= t) return false;
  return true;
}
int Solution::books(vector<int> &arr, int t) {
    if(t>arr.size()) return -1;
    
    int start=arr[0],end=0;
    for(int i: arr){
        end+=i;
        start=min(start,i);
    }
    while(start<=end){
        int mid=start+(end-start)/2;
        if(check(mid,arr,t)){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return start;
}
