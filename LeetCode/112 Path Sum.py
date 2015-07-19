# Definition for a binary tree node.
class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution:
    # @param {TreeNode} root
    # @param {integer} sum
    # @return {boolean}
    solved = False
    def hasPathSum(self, root, sum):
        self.solved = False
        self.solve(root, sum)
        return self.solved
        
    def solve(self, root, sum):
        if self.solved or root == None:
            return
        remaining = sum - root.val
        if remaining == 0 and root.left == None and root.right == None:
            self.solved = True
            return
        self.solve(root.left, remaining)
        self.solve(root.right, remaining)
