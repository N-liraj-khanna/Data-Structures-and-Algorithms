# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    paths=[]
    def dfs(self, root, st):
        
        if not root:
            return
        
        if not root.left and not root.right:
            self.paths.append(st+str(root.val))
            return 

        self.dfs(root.left, st+str(root.val)+"->")
        self.dfs(root.right, st+str(root.val)+"->")
        
        
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        self.paths=[]
        self.dfs(root, "")
        return self.paths