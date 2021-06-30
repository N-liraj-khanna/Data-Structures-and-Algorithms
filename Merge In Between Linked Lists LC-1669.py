# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        dummy=ListNode()
        temp=dummy
        temp.next=list1
        
        move=a
        while move:
          move-=1
          temp=temp.next
          
        start=temp
        
        move=b-a+2
        while move:
          move=move-1
          temp=temp.next
          
        end=temp
        
        start.next=list2
        while list2.next:
          list2=list2.next
        
        list2.next=end
        
        return dummy.next