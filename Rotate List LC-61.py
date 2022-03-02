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
        if(!head || !head->next && !k)
            return head;
        ListNode* temp=head;
        int count=0;
        while(temp->next){
            count++;
            temp=temp->next;
        }
        // if(k%count==0)
        //     return head;
        count=count-k%(count+1);
        temp->next=head;
        temp=temp->next;
        while(count--){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};

//MyApproach
/*
 if(!head)
            return NULL;
        ListNode* temp1=head;
        ListNode* temp2=head;
        int count=0;
        while(temp1){
            count++;
            temp1=temp1->next;
        }
        if(k%count==0)
            return head;
        if(k>=count)
            k=k%count;
        count=count-k-1;
        temp1=head;
        while(count){
            temp1=temp1->next;
            count--;
        }
        temp2=temp1->next;
        temp1->next=NULL;
        temp1=head;
        head=temp2;
        while(temp2->next){
            temp2=temp2->next;
        }
        temp2->next=temp1;
        return head;
*/