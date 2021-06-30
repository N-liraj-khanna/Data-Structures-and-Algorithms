"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
      
      if not head:
        return 
      
      temp=head
      while temp:
        copy=Node(temp.val)
        backup=temp.next
        temp.next=copy
        copy.next=backup
        temp=temp.next.next
      
      temp=head
      copy_head=head.next
      copy=copy_head
      
      while copy and copy.next:
        if temp.random:
          copy.random=temp.random.next
        else:
          copy.random=None
        temp=temp.next.next
        copy.next=copy.next.next
        copy=copy.next
      
      if temp and temp.random:
        copy.random=temp.random.next
      
      return copy_head
        
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
# Using map
#         if not head:
#           return 
        
#         copy_head = Node(head.val)
#         copy=copy_head
#         temp=head.next
        
#         map = {head: copy}
        
#         while temp:
#           copy.next=Node(temp.val)
#           copy=copy.next
            
#           map[temp]=copy
#           temp=temp.next
        
#         temp=head
#         copy=copy_head
                        
#         while temp:
#           if not temp.random:
#             copy.random=None
#           else:
#             copy.random=map[temp.random]  
#           temp=temp.next
#           copy=copy.next
          
#         return copy_head
          
          
          
          
          
          
          
          
          
          
          