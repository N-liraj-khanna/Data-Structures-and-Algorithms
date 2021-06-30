# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head:
          return
        
        dummy=ListNode(0,head)
        prev=dummy
        curr=next=dummy.next
        
        while next and next.next:
          next=curr.next.next
          prev.next=curr.next
          prev.next.next=curr
          curr.next=next
          prev=curr
          curr=next
          
        return dummy.next