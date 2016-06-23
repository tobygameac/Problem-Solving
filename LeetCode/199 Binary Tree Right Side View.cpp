class Solution {
 
 public:
  
  void RightSideView(TreeNode *node, size_t depth, std::vector<int> &ans) {
    if (!node) {
      return;
    }
    if (ans.size() <= depth) {
      ans.push_back(node->val);
    }
    RightSideView(node->right, depth + 1, ans);
    RightSideView(node->left, depth + 1, ans);
  }

  std::vector<int> rightSideView(TreeNode *root) {
    std::vector<int> ans;
    RightSideView(root, 0, ans);
    return ans;
  }

};
