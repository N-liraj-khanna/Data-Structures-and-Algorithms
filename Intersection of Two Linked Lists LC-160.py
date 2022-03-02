/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return NULL;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        
        /***Two Pointers***/
        
       // while(temp1!=temp2){
       //     if(temp1==NULL)
       //         temp1=headB;
       //     else 
       //         temp1=temp1->next;
       //     if(temp2==NULL)
       //         temp2=headA;
       //     else
       //         temp2=temp2->next;
       // }

       while(temp1!=temp2){
           temp1=temp1==NULL?headB:temp1->next;
           temp2=temp2==NULL?headA:temp2->next;
        }
        return temp1;
    }
};
//Simple One
/*
  struct ListNode* tempA=headA;
        struct ListNode* tempB=headB;
        while(tempA != NULL) {
            while(tempB != NULL) {
                if(tempA == tempB) {
                    return tempA;
                }
                tempB = tempB->next;
            }
            tempB = headB;
            tempA = tempA->next;
        }
        return NULL;
*/


//Simple looping
/*
ListNode* temp1=headA;
        ListNode* temp2=headB;
        if(headA==headB)
            return headA;
        while(temp1 && temp2){
            if(temp1==temp2->next)
                return temp1;
            else if(temp1->next==temp2)
                return temp2;
            else if(temp1->next==temp2->next)
                return temp1->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
*/

//Hashing
/*
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
      ListNode* temp1=headA;
        unordered_set<ListNode*> set;
        while(temp1){
            set.insert(temp1);
            temp1=temp1->next;
        }
        ListNode* temp2=headB;
        while(temp2){
            if(set.find(temp2)!=set.end())
                return temp2;
            temp2=temp2->next;
        }
        return NULL;
*/




