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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* out=new ListNode();
        ListNode* temp=out;
        int sum=0;
        
        while(head){
            if(head->val==0){
                temp->val=sum;
                sum=0;
                if(head->next){
                    temp->next=new ListNode();
                    temp=temp->next;
                }
            }else{
                sum+=head->val;
            }
            head=head->next;
        }
        return out->next;
    }
};