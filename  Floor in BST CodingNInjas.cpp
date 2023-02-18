// tc=o(n)
// sc=o(n)
#include <bits/stdc++.h> 
using namespace std;
void solve(TreeNode<int> *root, int x, int& res) {
    if(!root) return;
    if(root->val>x){
        solve(root->left,x,res);
    }else{
        res=max(res,root->val);
        solve(root->right,x,res);
    }
}
int floorInBST(TreeNode<int> *root, int X) {
  int res = -1;
  solve(root, X, res);
  return res;
}