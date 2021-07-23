##### -> Another Naive approach
##### -> Time Limit exceeded tho :(
##### -> the idea is, to find or search for the parent which has both the nodes as its 
##### -> child in its left side and its right side, and not in the same side
##### -> This solution works for Lowest Common ancestor 2 also in leetcode

class Solution:
    res=None
    
    def search(self, root, p, q):
        if not root:
            return False
        if root==p or root==q:
            return True
        return self.search(root.left, p, q) or self.search(root.right, p, q)
    
    def dfs(self, root, p, q):        
        if not root:
            return
        
        left_side = self.search(root.left, p, q)
        right_side=self.search(root.right, p, q)

        if not left_side and not right_side:
            return None

        if (left_side or p==root or q==root) and (right_side or p==root or q==root):
            self.res=root
            return 
        
        if left_side:
            self.dfs(root.left, p, q)
        if right_side:
            self.dfs(root.right, p, q)
        
        
    def lowestCommonAncestor3(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.dfs(root, p, q)
        return self.res

##### -> Naive approach
##### -> Trace the paths for both the values p and q
##### -> the first value from the reverse which is equal is the ancestor
##### -> This solution works for Lowest Common ancestor 2 also in leetcode

class Solution:
    path=[]
    def find(self, root, p, q, arr):

        if not root:
            return
        
        if root==p:
            self.path.append(arr+[root])
        
        if root==q:
            self.path.append(arr+[root])
        
        self.find(root.left, p, q, arr+[root])
        self.find(root.right, p, q, arr+[root])
        
            
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.path=[]
        
        self.find(root, p, q, [])
        path1=self.path[0]
        path2=self.path[1]
        
        if len(self.path)<=1:
            return None
                
        for i in range(len(path1)-1, -1, -1):
            for j in range(len(path2)-1, -1, -1):
                if path1[i]==path2[j]:
                    return path1[i]
            