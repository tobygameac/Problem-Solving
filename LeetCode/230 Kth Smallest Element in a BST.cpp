class Solution {

 public:

  int TreeSize(TreeNode *node) {
    return node ? (1 + TreeSize(node->left) + TreeSize(node->right)) : 0;
  }

  int kthSmallest(TreeNode *root, int k) {
    int left_size = TreeSize(root->left);
    if (k == left_size + 1) {
      return root->val;
    }
    if (k < left_size + 1) {
      return kthSmallest(root->left, k);
    }
    return kthSmallest(root->right, k - left_size - 1);
  }

};
