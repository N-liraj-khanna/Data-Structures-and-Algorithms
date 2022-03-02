// First approach(swapping the whole nodes)
class Solution {
public:
    void print(ListNode* h){
        while(h){
            cout<<h->val<<endl;
            h=h->next;
        }
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
            
        ListNode* dummy=new ListNode();
        dummy->next=head;
        
        ListNode* temp=dummy;
        
        ListNode* first;
        ListNode* first_prev;
        ListNode* second;
        ListNode* second_prev;
        
        // removing the two nodes and storing it in seperate pointers, with it's previous nodes
        int ptr=k;
        while(--ptr){
            temp=temp->next;
        }
        first_prev=temp;
        first=first_prev->next;
        
        temp=temp->next;
        second_prev=dummy;
        while(temp && temp->next){
            second_prev=second_prev->next;
            temp=temp->next;
        }
        
        second=second_prev->next;
        

         //swapping both nodes
        temp=second->next;//3
        second->next=first->next;
        first->next=temp;
        
        if(first_prev!=second)
            first_prev->next=second;
        else
            first->next=second;
        
        if(first!=second_prev)
            second_prev->next=first;
        else
            second->next=first;

        return dummy->next;
    }
};

//Second approach(just swapping value)
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
            
        ListNode* dummy=new ListNode();
        dummy->next=head;
        
        ListNode* temp=dummy;
        
        ListNode* first;
        ListNode* first_prev;
        ListNode* second;
        ListNode* second_prev;
        
        // removing the two nodes and storing it in seperate pointers, with it's previous nodes
        int ptr=k;
        while(--ptr){
            temp=temp->next;
        }
        first_prev=temp;
        first=first_prev->next;
        
        temp=temp->next;
        second_prev=dummy;
        while(temp && temp->next){
            second_prev=second_prev->next;
            temp=temp->next;
        }
        second=second_prev->next;
        if(first && second)
        swap(first->val,second->val);
        
            
        return dummy->next;
    }
};