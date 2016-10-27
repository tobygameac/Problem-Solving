class Solution {

 public:

  int PathSum(TreeNode *root, int sum, bool skippable) {
    if (!root) {
      return 0;
    }
    int answer = (root->val == sum) + PathSum(root->left, sum - root->val, false) + PathSum(root->right, sum - root->val, false);
    if (skippable) {
      answer += PathSum(root->left, sum, true) + PathSum(root->right, sum, true);
    }
    return answer;
  }

  int pathSum(TreeNode *root, int sum) {
    return PathSum(root, sum, true);
  }

};
