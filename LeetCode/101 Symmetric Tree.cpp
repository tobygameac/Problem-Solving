#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    return !root || check_symmetric(root->left, root->right);
  }
  
  bool check_symmetric(TreeNode *left_node, TreeNode *right_node) {
    if (!left_node && !right_node) {
      return true;
    }
    if (!left_node || !right_node) {
      return false;
    }
    if (left_node->val != right_node->val) {
      return false;
    }
    return check_symmetric(left_node->left, right_node->right) && check_symmetric(left_node->right, right_node->left);
  }
};

int main() {
  return 0;
}
