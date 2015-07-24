# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {integer[][]}
    def levelOrder(self, root):
        ans = []
        self.traverse(root, 0, ans)
        return ans

    def traverse(self, root, depth, ans):
        if root == None:
            return
        if len(ans) <= depth:
            ans.append([])
        self.traverse(root.left, depth + 1, ans);
        ans[depth].append(root.val)
        self.traverse(root.right, depth + 1, ans);
