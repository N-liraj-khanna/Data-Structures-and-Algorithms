// tc=O(n)
// sc=O(h)
class Solution {
    class Result{
    public:
        int sum;
        int maxi;
        int mini;
        Result(int sum, int maxi, int mini){
            this->sum=sum;
            this->maxi=maxi;
            this->mini=mini;
        }
    };

public:
    Result* solve(TreeNode* root, int& ans){

        if(!root) return new Result(0,INT_MIN,INT_MAX);

        Result* left=solve(root->left,ans);
        Result* right=solve(root->right,ans);
        
        if(left->maxi<root->val && root->val<right->mini){
            ans=max(ans,left->sum+right->sum+root->val);
            return new Result(left->sum+right->sum+root->val,max(root->val,right->maxi),min(root->val,left->mini));
        }
        return new Result(max(left->sum,right->sum),INT_MAX,INT_MIN);
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};

// tc=O(n)
// sc=O(h)
class Solution {
    class Result{
    public:
        int sum;
        int maxi;
        int mini;
        Result(int sum, int maxi, int mini){
            this->sum=sum;
            this->maxi=maxi;
            this->mini=mini;
        }
    };

public:
    Result* solve(TreeNode* root, int& ans){

        if(!root) return new Result(0,INT_MIN,INT_MAX);
        if(!root->left && !root->right){
            ans=max(ans,root->val);
            return new Result(root->val,root->val,root->val);
        }

        Result* left=solve(root->left,ans);
        Result* right=solve(root->right,ans);
        
        Result* res;
        
        if(left->maxi<root->val && root->val<right->mini){
            int rmin;
            int lmax;
            int sum;

            if(!root->right) rmin=root->val;
            else rmin=max(root->val,right->maxi);

            if(!root->left) lmax=root->val;
            else lmax=min(root->val,left->mini);

            sum=left->sum+right->sum+root->val;
            ans=max(ans,sum);
            res=new Result(sum,rmin,lmax);
        }else{
            res=new Result(max(left->sum,right->sum),INT_MAX,INT_MIN);
        }
        
        return res;

    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};