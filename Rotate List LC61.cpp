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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        ListNode *start=head;
        int len=1;
        while(start->next){
            len++;
            start=start->next;
        }
        start->next=head;
        k=len-(k%len);
        while(k--){
            start=start->next;
        }
        head=start->next;
        start->next=NULL;
        return head;
    }
};

// tc=o(n)
// sc=o(1)
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode *start=dummy, *end=dummy;
        int len=0;
        while(start->next){
            len++;
            start=start->next;
        }
        start=dummy;
        k=k%len;
        while(end->next){
            if(k==0){
                start=start->next;
            }else{
                k--;
            }
            end=end->next;
        }
        end->next=dummy->next;
        head=start->next;
        start->next=NULL;
        return head;
    }
};
