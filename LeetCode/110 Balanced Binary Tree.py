# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    balanced = True
    # @param {TreeNode} root
    # @return {boolean}
    def isBalanced(self, root):
        self.balanced = True
        self.traverse(root, 0);
        return self.balanced

    def traverse(self, root, depth):
        if root == None or not self.balanced:
            return depth
        left_depth = self.traverse(root.left, depth + 1)
        right_depth = self.traverse(root.right, depth + 1)
        if abs(left_depth - right_depth) > 1:
            self.balanced = False
        return max(left_depth, right_depth)
