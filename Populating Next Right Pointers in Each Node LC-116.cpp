// special method
// tc=o(n)
// sc=o(1)
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* node=root;
        Node* curr=root;
        Node* next;
        while(node->left){
            next=curr->left;
            while(curr){
                next->next=curr->right;
                next=next->next;
                if(curr->next){
                    next->next=curr->next->left;
                    next=next->next;
                }
                curr=curr->next;
            }
            curr=node->left;
            node=node->left;
        }
        return root;
    }
};

// dfs
// tc=o(n)
// sc=o(n)
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        if(!root->left && !root->right) return root;

        root->left->next=root->right;
        if(root->next)
            root->right->next=root->next->left;
        
        connect(root->left);
        connect(root->right);
        return root;
    }
};

// bfs
// tc=o(n)
// sc=o(n)
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        Node* prev=root;
        while(!q.empty()){
            int size=q.size()-1;
            for(int i=0;i<=size;i++){
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                if(i==0){
                    prev=q.front();
                }else{
                    prev->next=q.front();
                    prev=q.front();
                }
                q.pop();
            }
        }        
        return root;
    }
};