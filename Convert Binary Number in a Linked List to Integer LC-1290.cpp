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
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        int count=0,sum=0;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        cout<<count;
        temp=head;
        while(temp!=NULL){
            if(temp->val==1)
                sum+=(temp->val)*pow(2,count);
            count--;
            temp=temp->next;
        }

        return sum;
    }
};