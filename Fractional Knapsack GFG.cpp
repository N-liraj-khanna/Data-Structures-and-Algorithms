
// Time Complexity : O(NlogN)
// Auxilliary Space: O(1)
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    bool static cmp(Item a, Item b){
        return ((double)a.value/a.weight)>((double)b.value/b.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,cmp);
        double res=0;
        int i;
        for(i=0;i<n && W>=arr[i].weight;i++){
            res+=arr[i].value;
            W-=arr[i].weight;
        }
        if(i!=n) res+=(double)W*(arr[i].value/(double)arr[i].weight);
        return res;
    }
        
};