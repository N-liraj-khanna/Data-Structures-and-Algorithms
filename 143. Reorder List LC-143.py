# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: ListNode) -> None:
      """
      Do not return anything, modify head in-place instead.
      """
      
      stack = []
      fast=slow=head
      
      while fast and fast.next:
        # last=slow
        slow=slow.next
        fast=fast.next.next
      
      if fast and not fast.next:
        slow=slow.next
        
      prev=None
      curr=next=slow
      while curr:
        next=curr.next
        curr.next=prev
        prev=curr
        curr=next
      
      while prev:
        temp1=head.next
        head.next=prev
        head=head.next
        temp2=prev.next
        head.next=temp1
        
        prev=temp2
      
        
# #STACK
#     def reorderList(self, head: ListNode) -> None:
#       """
#       Do not return anything, modify head in-place instead.
#       """
      
#       stack = []
#       fast=slow=last=head
      
#       while fast and fast.next:
#         last=slow
#         slow=slow.next
#         fast=fast.next.next
      
#       if fast and not fast.next:
#         slow=slow.next
#         last=last.next
      
#       if last:
#         last.next=None
      
#       while slow:
#         stack.append(slow)
#         slow=slow.next
              
#       fast=head
      
#       while stack:
#         temp=fast.next
#         fast.next=stack.pop()
#         fast=fast.next
#         fast.next=temp
#         fast=fast.next
      
        