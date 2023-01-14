// tc=o(n/2+n/2+n/2)
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
    bool isPalindrome(ListNode* head) {
        ListNode *prev=NULL, *curr=head, *fast=head;
        while(fast && fast->next){
            curr=curr->next;
            fast=fast->next->next;
        }
        
        fast=curr;
        while(fast){
            fast=fast->next;
            curr->next=prev;
            prev=curr;
            curr=fast;
        }
        curr=head;
        while(prev){
            if(prev->val!=curr->val) return false;
            prev=prev->next;
            curr=curr->next;
        }
        return true;
    }
};