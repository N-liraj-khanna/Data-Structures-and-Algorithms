# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:

  class Node(object):
      def __init__(self, val):
          self.val = val

      def __repr__(self):
          return f'{self.val}'

      def __lt__(self, other):
          return self.val.val < other.val.val

        
  def mergeKLists(self, lists: List[ListNode]) -> ListNode:
    
    if not lists:
      return None
    
        
    heap=[]
    
    for li in lists:
      if li:
        heappush(heap,self.Node(li))
    
    head = ListNode()
    dummy = head
    while heap:
      temp = heappop(heap)
      dummy.next=ListNode(temp.val.val,None)
      if temp.val.next:
        heappush(heap,self.Node(temp.val.next))
      dummy=dummy.next
    
    return head.next
      
      


# HEAP
#       heap = []
#       for li in lists:
#         while li:
#           heappush(heap,li.val)
#           li=li.next

#       head = ListNode()
#       dummy = head

#       while heap:
#         dummy.next=ListNode(heappop(heap),None)
#         dummy=dummy.next

#       return head.next        

# Normal
#         array = []
#         for li in lists:
#           while li:
#             array.append(li.val)
#             li=li.next
#         array = sorted(array)

#         head = ListNode()
#         temp = head

#         for li in array:
#           temp.next=ListNode()
#           temp=temp.next
#           temp.val=li

#         return head.next

