# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        if not head: 
          return
        dummy=ListNode()
        dummy.next=head
        first=dummy
        second=dummy.next
        
        
        while second:
          if first.next.val<x:
            first=first.next
            second=second.next
          elif second.next and second.next.val<x:
            temp1=first.next
            temp2=second.next.next
            first.next=second.next
            first.next.next=temp1
            second.next=temp2
            first=first.next
          else:
            second=second.next
            
        return dummy.next