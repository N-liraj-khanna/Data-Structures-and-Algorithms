# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        new = ListNode()
        new_head=new
        carry=0
        
        while l1 or l2 or carry:
          new.next=ListNode()
          new=new.next
          
          add=0          
          if l1:
            add=add+l1.val
            l1=l1.next
          if l2:
            add=add+l2.val
            l2=l2.next
          if carry:
            add+=carry
            carry=0
          
          new.val=add%10
          carry=add//10
            

        return new_head.next