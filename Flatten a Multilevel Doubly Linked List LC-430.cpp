// tc=>O(sum(Nodes))
// sc=(1)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flat(Node* temp){
        while((temp && temp->child) || (temp && temp->next)){
            if(temp->child){
                Node *next=temp->next;
                temp->next=temp->child;
                temp->next->prev=temp;
                if(next) {
                    next->prev=flat(temp->child);
                    next->prev->next=next;
                }
                temp->child=NULL;
            }
            temp=temp->next;
        }
        return temp;
    }
    Node* flatten(Node* head) {
        flat(head);
        return head;
    }
};