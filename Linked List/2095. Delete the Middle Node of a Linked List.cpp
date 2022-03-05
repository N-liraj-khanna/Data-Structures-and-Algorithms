#1
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if(!head || !head->next) return NULL;
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast && fast->next){
            fast=fast->next->next;
            if(!fast || !fast->next){
                slow->next=slow->next->next;
                break;
            }
            slow=slow->next;
        }
        
        return head;
    }
};

#2

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if(!head || !head->next) return NULL;
        
        ListNode* slow=head;
        ListNode* fast=head->next->next;
        
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};