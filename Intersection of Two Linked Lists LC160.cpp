// Same thing as the two next but code modified
// tc=o(n)+o(n)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;

        ListNode *d1=headA,*d2=headB;
        while(d1!=d2){
            d1=d1?d1->next:headB;
            d2=d2?d2->next:headA;
        }
        return d1;
    }
};

// Same thing as the onenext but code modified, just swapped
// tc=o(n)+o(n)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *d1=headA, *d2=headB;
        while(d1 && d2){
            d1=d1->next;
            d2=d2->next;
        }

        if(d1){
            swap(d1,d2);
            swap(headA,headB);
        }

        d1=headB;
        while(d2){
            d1=d1->next;
            d2=d2->next;
        }
        d2=headA;

        while(d1 && d2){
            if(d1==d2) return d1;
            d1=d1->next;
            d2=d2->next;
        }
        return NULL;
    }
};

// tc=o(n)+o(n)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *d1=headA, *d2=headB;
        while(d1 && d2){
            d1=d1->next;
            d2=d2->next;
        }
        if(d1){
            d2=headA;
            while(d1){
                d1=d1->next;
                d2=d2->next;    
            }
            d1=headB;
        }else{
            d1=headB;
            while(d2){
                d1=d1->next;
                d2=d2->next;
            }
            d2=headA;
        }
        while(d1 && d2){
            if(d1==d2) return d1;
            d1=d1->next;
            d2=d2->next;
        }
        return NULL;
    }
};


// tc=o(n)+o(n)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1=0,c2=0;
        ListNode *d1=headA, *d2=headB;
        while(d1 && d2){
            d1=d1->next;
            d2=d2->next;
            c1++;
            c2++;
        }
        while(d1){
            d1=d1->next;
            c1++;           
        }
        while(d2){
            d2=d2->next;
            c2++;           
        }
        
        d1=headA;
        d2=headB;
        if(c1<c2){
            swap(c1,c2);
            swap(d1,d2);
        }
        int diff=c1-c2;
        while(diff--){
            d1=d1->next;
        }
        while(d1 && d2){
            if(d1==d2) return d1;
            d1=d1->next;
            d2=d2->next;
        }
        return NULL;
    }
};


// hashset
// tc=o(m)
// sc=o(n)
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
        unordered_set<ListNode*> set;
        while(headA){
            set.insert(headA);
            headA=headA->next;
        }
        while(headB){
            if(set.find(headB)!=set.end()){
                return headB;
            }
            headB=headB->next;
        }
        return NULL;
    }
};