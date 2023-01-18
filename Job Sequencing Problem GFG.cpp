// tc=o(nlogn)
// sc=o(n)
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    bool static cmp(Job a, Job b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n, cmp);
        vector<int> res={0,0};
        int maxi = arr[0].dead;
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, arr[i].dead);
        }
        vector<int> temp(maxi+1,-1);
        
        for(int i=0;i<n;i++){
            int curr=arr[i].dead;
            while(curr>=1 && temp[curr]!=-1) curr--;
            if(curr>0){
                res[0]++;
                res[1]+=arr[i].profit;
                temp[curr]=arr[i].profit;
            }
        }
        return res;
    } 
};