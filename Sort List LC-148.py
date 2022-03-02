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
 ListNode *findMid(ListNode *head,ListNode *tail)
    {
        ListNode *s = head, *f = head;
        
        while(f != tail && f->next != tail)
        {
            s = s->next;
            f = f->next->next;
        }
        
        return s;
        
    }
    
    ListNode *merge(ListNode *l1,ListNode *l2)
    {
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val > l2->val)
            swap(l1, l2);
        
        ListNode *res = l1;
        while(l1 && l2)
        {
            ListNode *tmp;
            while(l1 != NULL && l1->val <= l2->val)
            {
                tmp = l1;
                l1 = l1->next;
            }
            tmp->next = l2;
            
            swap(l1, l2);
            
        }
        return res;
    }
    
        
    ListNode *mergeSort(ListNode *head,ListNode *tail)
    {
        if(head == tail)
        {
            return (new ListNode(head->val));
        }
        
        ListNode *mid = findMid(head, tail);
        ListNode *head1 = mergeSort(head, mid);
        ListNode *head2 = mergeSort(mid->next, tail);
        
        head = merge(head1, head2);
        
        return head;
        
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next) return head;
        ListNode *tail = head;
        
        while(tail->next != NULL)
        {
            tail = tail->next;
        }
        
       return head = mergeSort(head, tail);
    }
};