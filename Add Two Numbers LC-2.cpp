// tc=O(max(n,m))
// sc=o(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* head=new ListNode();
        ListNode *temp=head;

        while(l1 || l2 || carry){
            temp->next=new ListNode();
            temp=temp->next;
            
            int add=carry;
            add+=l1?l1->val:0;
            add+=l2?l2->val:0;
            
            temp->val=add%10;
            carry=add/10;
            
            
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return head->next;
    }
};