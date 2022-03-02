# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        dummy=ListNode()
        dummy.next=head
        prev=dummy
        temp=dummy.next
        
        while temp:
          if temp.next and temp.val==temp.next.val:
            val=temp.val
            while temp and temp.val==val:
              delete_node=prev.next
              
              prev.next=prev.next.next
              temp=prev.next
              
              del delete_node
          else:
            prev=prev.next
            temp=temp.next
          
        return dummy.next