// tc=o(3n)
// sc=o(n)
#include <bits/stdc++.h> 


vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    if(!root) return {{}};
    
    vector<int> preorder,inorder,postorder; 
    stack<pair<BinaryTreeNode<int>*,int>> stk;

    stk.push({root,1});
    
    while(!stk.empty()){
        BinaryTreeNode<int>* node=stk.top().first;
        int num=stk.top().second;

        if(num==1){
            preorder.push_back(node->data);
            stk.top().second++;
            if(node->left)
                stk.push({node->left,1});
        }else if(num==2){
            inorder.push_back(node->data);
            stk.top().second++;
            if(node->right)
                stk.push({node->right,1});
        }else{
            postorder.push_back(node->data);
            stk.pop();
        }
    }

    return {inorder,preorder,postorder};
}