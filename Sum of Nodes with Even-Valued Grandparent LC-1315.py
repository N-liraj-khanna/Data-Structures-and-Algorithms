
### WIERD OVERWORK APPROCH for fun and was bored :)
### Won't work on Leetcode, will show Time Limit Excceeded

### Idea came from Heap(obviously by formulas)

#### Stuffs Hapening
##### -> Make and array with all the values in the binary tree using level order/BFS approach
##### -> Created the array with null values as '-1' as exactly in the order. Every level has it's null value as -1
##### ->     8                8
##### ->     \              /  \
##### ->     4       ->   -1     4 
##### ->    / \           / \   / \ 
##### ->    4  1         -1 -1 4  1
##### -> For this binary tree the array will be like this: 
##### -> [8,-1,4,-1,-1,4,1]
##### -> This is normal level order traversal, with an extention. Will break out of the loop with the depth.
##### -> By finding the depth of the whole tree, we can break out of the loop one less when the queue's size becomes
##### -> more than the 2 power of the depth(Logically)
##### -> Now iterate throughout the array, when even number hits add their grandchildren's value to the resultant sum
##### -> Also check if the index is less than the overall length of the array made from tree, if so ignore those values
##### -> Also check if the value is -1, if so that values dosent exist so ignore em too.
##### -> Add em if inside the array as they're the grandchildren
```
class Solution:
    
    def depth(self, root, n):
        if not root:
            return n
        return max(self.depth(root.left, n+1),self.depth(root.right, n+1))
    
    def bfs(self, root):
        queue=[root]
        tree=[root.val]
        depth=self.depth(root, 0)-1
        
        while queue and len(queue)<2**depth:
            if queue[0].left:
                queue.append(queue[0].left)
                tree.append(queue[0].left.val)
            else:
                queue.append(TreeNode(-1))
                tree.append(-1)
            
            if queue[0].right:
                queue.append(queue[0].right)              
                tree.append(queue[0].right.val)
            else:
                queue.append(TreeNode(-1))
                tree.append(-1)
            queue.pop(0)
            
        return tree
        
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        tree=self.bfs(root)
        sum=0
        for i in range(0, len(tree)):
            if tree[i]%2==0:
                first=2*i+1
                second=2*i+2
                
                first_children1=2*first+1 #11
                first_children2=2*first+2 #12
                second_children1=2*second+1 #13
                second_children2=2*second+2 #14
                
                if first_children1<len(tree) and tree[first_children1]!=-1 :
                    # print(tree[2*first+1])
                    sum+=tree[first_children1]
                    
                if first_children2<len(tree) and tree[first_children2]!=-1:
                    # print(tree[2*first+2])
                    sum+=tree[first_children2]
                    
                if second_children1<len(tree) and tree[second_children1]!=-1:
                    # print(tree[2*second+1])
                    sum+=tree[second_children1]
                    
                if second_children2<len(tree) and tree[second_children2]!=-1:
                    # print(tree[2*second+2])
                    sum+=tree[second_children2]
                    
        print(tree)
        return sum
```

##### -> Another Approach, Just do a dfs for all the nodes
##### -> While doing dfs, if any value has even value just call the other grandparent function
##### -> Grandparent function will go two lvl deep and add the sum of that nodes grandparent to the global sum value
##### -> Still a over time solution
```
class Solution:
    sum=0
    def grandparent(self, root, lvl):
        if not root:
            return
        if lvl==2:
            self.sum+=root.val
        self.grandparent(root.left, lvl+1)
        self.grandparent(root.right, lvl+1)
    
    def dfs(self, root):
        if not root:
            return
        if root.val%2==0:
            self.grandparent(root, 0)
        self.dfs(root.left)
        self.dfs(root.right)
        
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        self.dfs(root)
        return self.sum
```
        
### -> The Best and most optimal Aproach, sending the parent and grandoparent along with every node respectively
```
class Solution:
    def grandparent(self, root, parent, grand, sum):
        if not root:
            return sum
        
        if grand and grand.val%2==0:
            sum+=root.val
            
        sum=self.grandparent(root.left, root, parent, sum)
        sum=self.grandparent(root.right, root, parent, sum)
        
        return sum
        
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        return self.grandparent(root, None, None, 0)
```