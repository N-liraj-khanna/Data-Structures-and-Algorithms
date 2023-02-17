
// tc=o(n)
// tc=o(n)
#include <bits/stdc++.h> 
using namespace std;

void solve(BinaryTreeNode<int>* root, int key, pair<int,int>& res){
    if(!root) return;

    if(key>root->data){
        int left=res.first==-1?root->data:max(res.first,root->data);
        res.first=left;

        solve(root->right,key,res);
    }else if(key<root->data){
        int right=res.second==-1?root->data:min(res.second,root->data);
        res.second=right;

        solve(root->left,key,res);
    }else{
        solve(root->left,key,res);
        solve(root->right,key,res);
    }
    
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key){
    pair<int,int> res={-1,-1};
    solve(root,key,res);
    return res;
}
