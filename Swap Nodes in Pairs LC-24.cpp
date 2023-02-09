// tc=o(n)
// sc=o(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy=new ListNode();
        dummy->next=head;
        head=dummy;
        while(head->next && head->next->next){
            ListNode* temp=head->next;
            head->next=temp->next;
            head=head->next;
            temp->next=head->next;
            head->next=temp;
            head=head->next;
        }
        return dummy->next;
    }
};