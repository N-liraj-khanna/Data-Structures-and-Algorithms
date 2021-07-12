# TC => O(N) SC => O(H), H is the max height/depth of the tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root, n):
      if not root:
        return n
      return max(self.dfs(root.left, n+1),self.dfs(root.right, n+1))
    def maxDepth(self, root: TreeNode) -> int:
        return self.dfs(root, 0)