# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  
    def reverse(self, head: ListNode, k: int):
      
        prev=None
        curr=next=head
        
        list_tail = head
      
        while k:
          next=curr.next
          curr.next=prev
          prev=curr
          curr=next

          k = k - 1

        list_tail.next = curr 
        list_head = prev
        return list_head, list_tail
  
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
      
        main_head=None
        
        num=0
        slow=fast=head
        
        while fast and fast.next:
          slow=slow.next
          fast=fast.next.next
          num+=1
        
        if not fast:
          num = num * 2
        elif not fast.next:
          num = num * 2 + 1
          
        num=num-(num%k)-k
        
        main_head, main_tail = self.reverse(head, k)
        
        while num>0:
          num = num - k
          main_tail.next, main_tail=self.reverse(main_tail.next,k)
        
        return main_head
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          