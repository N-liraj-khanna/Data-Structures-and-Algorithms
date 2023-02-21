// tc=o(n)+o(n)
// sc=o(n)+o(n)
c/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string res="";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            res+=q.front()==NULL?"N,":(to_string(q.front()->val)+",");
            int size=q.size();
            TreeNode* node=q.front();
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
            q.pop();
        }
        res.pop_back();
        return res;
    }

    pair<int,int> getVal(string& data, int i){
        if(data[i]=='N') return {i+2,INT_MIN};
        int op=0;
        bool flag=false;
        if(data[i]=='-'){
            i++;
            flag=true;
        }

        while(data[i]!=',' && i<data.size()){
            op=op*10+(data[i]-'0');
            i++;
        }
        return {i+1,flag?-1*op:op};
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;

        pair<int,int> val=getVal(data,0);
        int idx=val.first;
        TreeNode* root=new TreeNode(val.second);

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty() && idx<data.size()){
            TreeNode* node=q.front();

            val=getVal(data,idx);
            idx=val.first;
            if(val.second==INT_MIN){
                node->left=NULL;
            }else{
                node->left=new TreeNode(val.second);
                q.push(node->left);
            }

            val=getVal(data,idx);
            idx=val.first;
            if(val.second==INT_MIN){
                node->right=NULL;
            }else{
                node->right=new TreeNode(val.second);
                q.push(node->right);
            }

            q.pop();
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));