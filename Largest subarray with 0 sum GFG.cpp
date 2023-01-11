// O(N)
// O(N)
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int prefix=0,maxi=0;
        unordered_map<int,int> map;
        
        for(int i=0;i<n;i++){
            prefix+=A[i];
            if(prefix==0){
                maxi=i+1;  
            }else if(map.find(prefix)==map.end()){
                map[prefix]=i;   
            }else{
                maxi=max(maxi,i-map[prefix]);                
            }
        }
        return maxi;
    }
};
