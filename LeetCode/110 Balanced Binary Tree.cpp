class Solution {
 
 public:
  
  bool isBalanced(TreeNode *root) {
    return root ? (isBalanced(root->left) && isBalanced(root->right) && std::abs(Depth(root->left) - Depth(root->right)) <= 1) : true;
  }

  int Depth(TreeNode *node) {
    return node ? (1 + std::max(Depth(node->left), Depth(node->right))) : 0;
  }

};
