
class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        Node* temp=new Node(0);
        temp->next=head;
        head=temp;
        while(temp && temp->next){
            if(temp->next->data>data) break;
            temp=temp->next;
        }
        Node* insert=new Node(0);
        insert->data=data;
        insert->next=temp->next;
        temp->next=insert;
        return head->next;
    }
};
