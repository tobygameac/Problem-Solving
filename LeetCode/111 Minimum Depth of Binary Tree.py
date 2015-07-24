# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {integer}
    def minDepth(self, root):
        if root == None:
            return 0
        return self.traverse(root, 0);

    def traverse(self, root, depth):
        if root == None:
            return 2e9
        if root.left == None and root.right == None:
            return depth + 1
        return min(self.traverse(root.left, depth + 1), self.traverse(root.right, depth + 1))
