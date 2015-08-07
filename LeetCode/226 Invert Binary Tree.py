# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {TreeNode}
    def invertTree(self, root):
        if not root:
            return None
        inverted_node = TreeNode(root.val)
        inverted_node.right = self.invertTree(root.left)
        inverted_node.left = self.invertTree(root.right)
        return inverted_node
