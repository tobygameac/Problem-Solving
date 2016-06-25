class Solution {
 
 public:
  
  bool PreOrderCheck(TreeNode *node, int &index, int &current_value) {
    if (!node) {
      return true;
    }
    if (!PreOrderCheck(node->left, index, current_value)) {
      return false;
    }
    if (index && (current_value >= node->val)) {
      return false;
    }
    current_value = node->val;
    ++index;
    return PreOrderCheck(node->right, index, current_value);
  }

  bool isValidBST(TreeNode *root) {
    int index = 0, current_value = 0;
    return PreOrderCheck(root, index, current_value);
  }

};
