// tc=o(1)
// sc=o(1)
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
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};

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
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
        /*ListNode* temp=node;
        while(temp->next!=NULL){                
            temp=temp->next;
            node->val=temp->val;
            if(temp->next==NULL)
                node->next=NULL;
            else
                node=node->next;                
        }
        delete temp;*/
    }
};