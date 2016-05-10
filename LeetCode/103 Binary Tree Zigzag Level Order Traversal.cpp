class Solution {
 
 public:
  
  std::vector<std::vector<int> > zigzagLevelOrder(TreeNode *root) {
    std::vector<std::vector<int> > results;
    Traverse(root, 0, results);
    for (size_t i = 1; i < results.size(); i += 2) {
      std::reverse(results[i].begin(), results[i].end());
    }
    return results;
  }

  void Traverse(TreeNode *node, size_t row, std::vector<std::vector<int> > &results) {
    if (!node) {
      return;
    }
    Traverse(node->left, row + 1, results);
    if (results.size() <= row) {
      results.resize(row + 1);
    }
    results[row].push_back(node->val);
    Traverse(node->right, row + 1, results);
  }

};
