# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def helper(self, root: TreeNode, targetSum: int, sum: int) -> bool:
    
    if not root:
      return False
    
    if not root.left and not root.right and targetSum==(sum+root.val):
      print(sum)
      return True
      
    
    return self.helper(root.left,targetSum,sum+root.val) or\
      self.helper(root.right,targetSum,sum+root.val)
  
  def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        return self.helper(root, targetSum, 0)