# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    
    def reverse(self,head: ListNode, n: int):
      
      prev = head
      curr = next = head.next
      
      while n:
        n = n - 1
        
        if curr:
          next=curr.next
          curr.next=prev
          prev=curr
          curr=next
      
      if head.next:
        head.next.next = curr
        head.next = prev
        
    
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
       
        if not head:
          return
        
        dummy = ListNode()
        temp=dummy
        temp.next=head
        
        n=left
        while n>1:
          n=n-1
          temp=temp.next
          
        self.reverse(temp, right-left+1)
        return dummy.next
          
          
          
          
          
          
          
          
          
          
          
          
          