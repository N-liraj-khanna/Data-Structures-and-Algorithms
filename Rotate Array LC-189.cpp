class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        if(nums.size()>1 && k>0 && nums.size()!=k){
            int j=0, n=nums.size();
            vector<int> vis(n,0);
            while(vis[j]==0){
                int i=j;
                int temp1=nums[i], temp2;
                while(vis[i]==0){
                    temp2=nums[(i+k)%n];
                    nums[(i+k)%n]=temp1;
                    temp1=temp2;
                    vis[i]=1;
                    i=(i+k)%n;
                }
                j++;
            }
        }
    }
};