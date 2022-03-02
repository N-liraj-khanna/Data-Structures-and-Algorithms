# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
      
      dummy = ListNode()
      fast = slow = dummy
      slow.next=fast.next=head
      
      print(slow)
      
      num = n + 1
      while fast:
        if num<=0:
          slow=slow.next
        fast=fast.next
        num = num - 1
      
      print(slow)
      
      slow.next=slow.next.next
      
      return dummy.next
      
# Normal Approach
#       temp=head
#       num = 0
#       while temp:
#         temp=temp.next
#         num = num + 1
      
#       dummy=ListNode()
#       dummy.next=head
#       temp=dummy
      
      
#       num = num - n
      
#       while num>0:
#         temp=temp.next
#         num = num - 1
      
#       temp.next = temp.next.next
      
#       return dummy.next