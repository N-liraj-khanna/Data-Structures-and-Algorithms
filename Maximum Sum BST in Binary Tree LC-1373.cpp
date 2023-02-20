// mine, wrong
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
        
        cout<<root->val<<endl;
        cout<<"left "<<left->sum<<" "<<left->maxi<<" "<<left->mini<<endl;
        cout<<"right "<<right->sum<<" "<<right->maxi<<" "<<right->mini<<endl;
        
        Result* res;
        
        if(left->maxi<root->val && root->val<right->mini){
            int rmin;
            int lmax;
            int sum;

            if(!root->right) rmin=root->val;
            else rmin=max(root->val,right->mini);

            if(!root->left) lmax=root->val;
            else lmax=min(root->val,left->maxi);

            sum=left->sum+right->sum+root->val;
            ans=max(ans,sum);
            res=new Result(sum,rmin,lmax);
        }else{
            res=new Result(max(left->sum,right->sum),INT_MAX,INT_MIN);
        }
        
        cout<<res->sum<<" "<<res->maxi<<" "<<res->mini<<endl;

        return res;

    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};


// reffered
int ans;
class prop{
public:
    bool bst;    
    int ma;       
    int mi;         
    int ms;     
    prop(){
        bst=true;
        ma=INT_MIN;
        mi=INT_MAX;
        ms=0;
    }
};
class Solution {
public:
    prop calcSum(TreeNode* root){
        if (root == NULL){
            return prop();
        }
        prop p;
        prop pl = calcSum(root->left);                       
        prop pr = calcSum(root->right);                     
		
        if ( pl.bst==true && pr.bst==true && root->val>pl.ma && root->val<pr.mi ){
            p.bst = true;                                                    
            p.ms = pl.ms + pr.ms + root->val;          
            p.mi  = min(root->val, pl.mi);
            p.ma = max(root->val, pr.ma);
        }
        else {
            p.bst=false;
            p.ms=max(pl.ms, pr.ms);
        }
		
        ans=max(ans, p.ms);
        return p;
    }
    int maxSumBST(TreeNode* root){
        ans = 0;
        calcSum(root);
        return ans;
    }
};