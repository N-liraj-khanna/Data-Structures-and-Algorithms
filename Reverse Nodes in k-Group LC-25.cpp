// My Way
// tc=o(n)
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=0;
        ListNode *temp=head;
        while(temp){
            temp=temp->next;
            len++;
        }
        temp=head;
        ListNode* temp1=NULL;
        ListNode *prev=NULL, *curr=head, *next=head;
        for(int i=len;i>=k;i-=k){
            for(int j=0;j<k;j++){
                next=next->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            if(len==i) head=prev;
            if(temp1)temp1->next=prev;
            temp1=temp;
            temp=curr;
            prev=NULL;
        }
        temp1->next=curr;
        return head;
    }
};

// Striver way
// just swap each lines by storing previous
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=0;
        ListNode *dummy=new ListNode();
        dummy->next=head;
        while(head){
            head=head->next;
            len++;
        }
        head=dummy->next;
        ListNode *prev=dummy, *curr, *next;
        while(len>=k){
            curr=prev->next;
            next=curr->next;
            for(int j=1;j<k;j++){
                curr->next=next->next;
                next->next=prev->next;
                prev->next=next;
                next=curr->next;
            }
            len-=k;
            prev=curr;
        }
        return dummy->next;
    }
};