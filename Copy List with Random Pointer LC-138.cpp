// Intuitive stuff
// tc=o(n)
// sc=o(n)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node *temp1=head, *temp2;
        Node *copy_head;

        while(temp1){
            temp2=temp1->next;
            temp1->next=new Node(temp1->val);
            temp1=temp1->next;
            temp1->next=temp2;
            temp1=temp2;
        }
        
        temp1=head;
        while(temp1){
            temp1->next->random=temp1->random?temp1->random->next:NULL;
            temp1=temp1->next->next;
        }

        copy_head=head->next;
        temp1=head;
        while(temp1){
            temp2=temp1->next;
            temp1->next=temp2->next;
            temp1=temp1->next;
            temp2->next=temp1?temp1->next:NULL;
        }
        return copy_head;
    }
};

// Hashmap
// tc=o(n)
// sc=o(n)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        Node* temp=head;
        Node *copy_head=new Node(0);
        Node* copy=copy_head;
        
        unordered_map<Node*,Node*> map;

        while(temp){
            copy->next=new Node(temp->val);
            copy=copy->next;
            map[temp]=copy;
            temp=temp->next;
        }
        copy=copy_head->next;
        temp=head;
        while(temp){
            copy->random=map[temp->random];
            copy=copy->next;
            temp=temp->next;
        }
        return copy_head->next;
    }
};