class Solution {
 
 public:
  
  struct Sum {
    int child_sum;
    int self_and_grand_children_sum;
  };

  Sum Rob(TreeNode *root) {
    if (!root) {
      return Sum{0, 0};
    }
    Sum left_sum = Rob(root->left);
    Sum right_sum = Rob(root->right);
    int child_sum = std::max(left_sum.child_sum, left_sum.self_and_grand_children_sum) + std::max(right_sum.child_sum, right_sum.self_and_grand_children_sum);
    int self_and_grand_children_sum = root->val + left_sum.child_sum + right_sum.child_sum;
    return Sum{child_sum, self_and_grand_children_sum};
  }

  int rob(TreeNode* root) {
    Sum sum = Rob(root);
    return std::max(sum.child_sum, sum.self_and_grand_children_sum);
  }

};
