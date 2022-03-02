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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while(head){
            if (set.find(head) != set.end())
                return true;
            set.insert(head);
            head=head->next;
        }
        return false;
    }
};
//Fast and SLow Pointer
/*
        if(head==NULL || head->next==NULL)
            return false;
        ListNode* t1=head;
        ListNode* t2=head->next;
            while(t2->next!=NULL && t2->next->next!=NULL){
                if(t1==t2)
                    return true;
                t1=t1->next;
                t2=t2->next->next;
            }
        return false;
        */