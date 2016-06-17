class Solution {

 public:
  
  void MaxPathSum(TreeNode *node, int &sum, int &ans) {
    if (!node) {
      return;
    }
    int left_sum = sum;
    int right_sum = sum;
    MaxPathSum(node->left, left_sum, ans);
    MaxPathSum(node->right, right_sum, ans);
    sum = std::max(0, std::max(left_sum, right_sum)) + node->val;
    int turned_sum = left_sum + right_sum + node->val;
    ans = std::max(ans, std::max(sum, turned_sum));
  }

  int maxPathSum(TreeNode* root) {
    int sum = 0, ans = -2e9;
    MaxPathSum(root, sum, ans);
    return ans;
  }

};
