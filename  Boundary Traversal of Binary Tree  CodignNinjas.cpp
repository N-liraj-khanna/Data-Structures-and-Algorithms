// tc=o(n+n+n)
// sc=o(n+n)
#include <bits/stdc++.h> 
using namespace std;

bool isLeaf(TreeNode<int>* root){
    if(!root) return false;
    if(!root->left && !root->right)
        return true;
    else
        return false;
}

void left(TreeNode<int>* root, vector<int>& res){
    TreeNode<int>* node=root->left;
    while(node){
        if(!isLeaf(node)) res.push_back(node->data);
        if(node->left) node=node->left;
        else node=node->right;
    }
}

void leaves(TreeNode<int>* root, vector<int>& res){
    if(!root) return;
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    leaves(root->left,res);
    leaves(root->right,res);
}

void right(TreeNode<int>* root, vector<int>& res){
    TreeNode<int>* node=root->right;
    stack<int> stk;
    while(node){
        if(!isLeaf(node)) stk.push(node->data);
        if(node->right) node=node->right;
        else node=node->left;
    }
    while(!stk.empty()){
        res.push_back(stk.top());
        stk.pop();
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    if(!root) return {};
    if(isLeaf(root)) return {root->data};

    vector<int> res;
    res.push_back(root->data);

    left(root,res);
    leaves(root,res);
    right(root,res);
    
    return res;
}