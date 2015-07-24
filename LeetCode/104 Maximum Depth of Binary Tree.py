# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {integer}
    def maxDepth(self, root):
        return self.traverse(root, 0)

    def traverse(self, root, depth):
        if root == None:
            return depth
        return max(self.traverse(root.left, depth + 1),
                   self.traverse(root.right, depth + 1))
