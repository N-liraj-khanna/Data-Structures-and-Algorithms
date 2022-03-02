# The Naive approach and Yea approach
# Calculate depth in one fucntion,
# in another fucntion, only when the counter reaches 1 add that value to result, that is the deepest leaves
# TC => O(2N) SC => O(H), H is the depth/height

class Solution:
    res = 0

    def count(self, root, n):
        if not root:
            return n
        return max(self.count(root.left, n+1), self.count(root.right, n+1))

    def sum(self, root, n):
        if not root:
            return
        if n == 1:
            self.res += root.val

        self.sum(root.left, n-1)
        self.sum(root.right, n-1)

    def deepestLeavesSum(self, root: TreeNode) -> int:
        n = self.count(root, 0)
        self.sum(root, n)
        return self.res


# Another code, one traversal but using a map t track of each levels sum
# inderect BFS
# TC => O(N) SC=> O(2H), 2H because recursion stack and map
class Solution:
    def sum(self, root, n, lvl_map):
        if not root:
            return lvl_map

        if not lvl_map.get(n):
            lvl_map[n] = root.val
        else:
            lvl_map[n] += root.val

        self.sum(root.left, n+1, lvl_map)
        self.sum(root.right, n+1, lvl_map)
        return lvl_map

    def deepestLeavesSum(self, root: TreeNode) -> int:
        lvl_map = self.sum(root, 0, {})

        return lvl_map[len(lvl_map)-1]


# BFS
# Another Awesome solution which uses breath first search solution
# uses queue to take in all the level nodes also add the values in it
# at the last level/traversal is the deepest leaves nodes, that time the sum will be returned
# TC => O(N) SC => O(B), where B is the max breath of tree
class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:

        def height(root):
            if not root:
                return 0
            return 1+max(height(root.left), height(root.right))

        h = height(root)
        q = deque()
        q.append((root, 1))
        s = 0
        while q:
            r, x = q.popleft()
            if x == h:
                s += r.val

            if r.left:
                q.append([r.left, x+1])
            if r.right:
                q.append([r.right, x+1])

        return s
