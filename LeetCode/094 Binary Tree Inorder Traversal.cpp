class Solution {

 public:
  
  void InorderTraversal(TreeNode *node, std::vector<int> &ans) {
    if (node) {
      InorderTraversal(node->left, ans);
      ans.push_back(node->val);
      InorderTraversal(node->right, ans);
    }
  }

  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> ans;
    InorderTraversal(root, ans);
    return ans;
  }

};
