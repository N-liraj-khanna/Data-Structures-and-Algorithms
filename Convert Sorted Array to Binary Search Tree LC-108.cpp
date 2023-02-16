// tc=o(n)
// sc=o(n)
class Solution {
public:

    TreeNode* solve(int s, int e, vector<int>& nums){
        int mid=s+(e-s)/2;
        if(s>e) return NULL;



        TreeNode* node=new TreeNode(nums[mid]);
        node->left=solve(s,mid-1,nums);
        node->right=solve(mid+1,e,nums);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size()-1;
        return solve(0,n,nums);
    }

};