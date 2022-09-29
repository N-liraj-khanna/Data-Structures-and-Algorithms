#1
class Solution {
public:
    int pairSum(ListNode* head) {
        int out=0;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        ListNode* prev=NULL;
        ListNode* curr=slow;
        ListNode* next=slow;
        while(curr){
            next=next->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        out=head->val+prev->val;
        while(head->next){
            head=head->next;    
            prev=prev->next;
            out=max(out, head->val+prev->val);
        }
        
        return out;
    }
};

#2
class Solution {
public:
    int pairSum(ListNode* head) {
        int out=INT_MIN;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        
       stack<int> stk;
        while(slow){
            stk.push(slow->val);
            slow=slow->next;
        }

        while(!stk.empty()){
            out=max(out,stk.top()+head->val);
            stk.pop();
            head=head->next;
        }
        
        return out;
    }
};