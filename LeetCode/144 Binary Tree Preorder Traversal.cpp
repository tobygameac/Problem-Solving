class Solution {

 public:

  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> ans;
    std::stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()) {
      TreeNode *node = s.top();
      s.pop();
      if (!node) {
        continue;
      }
      ans.push_back(node->val);
      s.push(node->right);
      s.push(node->left);
    }
    return ans;
  }

};
