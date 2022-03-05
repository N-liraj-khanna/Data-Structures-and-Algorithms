#1
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int n=0;
        while(temp){
            temp=temp->next;
            n++;
        }
        temp=head;
        for(int i=0;i<n/2;i++){
            temp=temp->next;
        }
        return temp;
    }
};
#2
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* second=head;
        while(second && second->next){
            head=head->next;
            second=second->next->next;
        }
        return head;
    }
};