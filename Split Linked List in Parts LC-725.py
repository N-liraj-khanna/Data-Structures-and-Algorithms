# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: ListNode, k: int) -> List[ListNode]:
        res = []
        length = 0
        
        temp = head
        while temp:
          length += 1
          temp = temp.next
        
        max_chunk = (length // k) + 1
        num_max_chuck_nodes = length % k
        
        temp=head
        while temp:
          res.append(temp)
          if num_max_chuck_nodes:
            move = max_chunk
            num_max_chuck_nodes -= 1
          else:
            move = max_chunk - 1  # to the end array with less num of nodes
          move -= 1  # Cuz its one indexed
          while temp.next and move:
            move -= 1
            temp=temp.next
          back_up=temp.next
          temp.next=None
          temp=back_up
        
        while len(res)<k:
          res.append(None)
        
        return res
          