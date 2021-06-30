# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        
        if not head:
          return
        
        head1=ListNode()
        head2=ListNode()
        
        head1.next=head
        head2.next=head.next
        
        head1=head1.next
        head2=head2.next
        main_head2=head2
        
        while head2 and head2.next:
          head1.next=head2.next
          head1=head1.next
          
          head2.next=head1.next
          head2=head2.next
          
        head1.next=main_head2
        
        return head
          
          