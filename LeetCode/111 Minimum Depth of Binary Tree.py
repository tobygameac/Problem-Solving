# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    min_depth = 0
    # @param {TreeNode} root
    # @return {integer}
    def minDepth(self, root):
        if root == None:
            return 0
        self.min_depth = 2e9
        self.traverse(root, 0);
        return self.min_depth

    def traverse(self, root, depth):
        if root == None:
            return
        if root.left == None and root.right == None:
            self.min_depth = min(self.min_depth, depth + 1);
            return
        self.traverse(root.left, depth + 1)
        self.traverse(root.right, depth + 1)
