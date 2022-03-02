# 1st
# Normal approach using true and false, using a different function
class Solution:
    
  def dfs(self, root):
      if not root:
          return True
              
      if not root.left and not root.right and root.val==0:
          return True
      
      left=self.dfs(root.left)
      right=self.dfs(root.right)
      
      if left:
          root.left = None
      if right:
          root.right = None
      
      if left and right and root.val==0:
          return True
      
      return False
  
  def pruneTree(self, root: TreeNode) -> TreeNode:
      if self.dfs(root):
          return None
      return root
      

# 2nd
# Optimal approach, same complexity as above, still this is done in 
# same fucntion, by returning the root and node itself
class Solution:
  
  def pruneTree(self, root: TreeNode) -> TreeNode:
      if not root:
        return root
    
    root.left=self.pruneTree(root.left)
    root.right=self.pruneTree(root.right)
    
    if root.val==0 and not root.left and not root.right:
        return None
    
    return root
          