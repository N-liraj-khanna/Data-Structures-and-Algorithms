// tc=o(n)
// sc=o(n)
#include <bits/stdc++.h> 
using namespace std;
int solve(BinaryTreeNode < int > * root){
    if(!root) return 0;
    if(!root->left && !root->right) return root->data;
    
    int sum=0;
                                                                                                                                                                                                                                                                                                                                                                                                            
    if(root->left) sum+=root->left->data;
    if(root->right) sum+=root->right->data;

    if(sum>=root->data) root->data=sum;
    else{
        if(root->left) root->left->data=root->data;
        if(root->right) root->right->data=root->data;
    }

    int lh=solve(root->left);
    int rh=solve(root->right);
    root->data=lh+rh;
    return root->data;
    

}
void changeTree(BinaryTreeNode < int > * root) {
    solve(root);
}  