// tc=o(n)
// sc=o(n)
#include <bits/stdc++.h> 
void solve(BinaryTreeNode<int> *root, int x, int& res) {
    if(!root) return;
    if(root->data>=x){
        res=root->data;
        solve(root->left,x,res);
    }else{
        solve(root->right,x,res);
    }
}
int findCeil(BinaryTreeNode<int> *root, int x){
  int res = -1;
  solve(root, x, res);
  return res;
}