# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: ListNode, k: int) -> ListNode:  
      if not head:
        return

      first=slow=fast=head

      while fast.next:
        if k>1:
          fast=fast.next
          first=fast
          k-=1
        else:
          slow=slow.next
          fast=fast.next

      first.val,slow.val=slow.val,first.val
      return head 
        
          