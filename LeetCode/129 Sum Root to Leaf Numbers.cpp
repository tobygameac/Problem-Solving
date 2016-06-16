class Solution {

 public:
  
  int SumNumbers(TreeNode* root, int sum) {
    if (!root) {
      return 0;
    }
    sum = sum * 10 + root->val;
    if (!(root->left || root->right)) {
      return sum;
    }
    return SumNumbers(root->left, sum) + SumNumbers(root->right, sum);
  }

  int sumNumbers(TreeNode* root) {
    return SumNumbers(root, 0);
  }

};
