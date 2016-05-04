#include <cstdio>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 
 public:

  std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
    std::vector<int> path;
    std::vector<std::vector<int>> answer;
    FindPath(root, sum, path, answer);
    return answer;
  }

  void FindPath(TreeNode *node, int need, std::vector<int> &current_path, std::vector<std::vector<int> > &solutions) {
    if (!node) {
      return;
    }

    current_path.push_back(node->val);
    if (need == node->val) {
      if (!node->left && !node->right) {
        solutions.push_back(current_path);
      }
    }
    FindPath(node->left, need - node->val, current_path, solutions);
    FindPath(node->right, need - node->val, current_path, solutions);
    current_path.pop_back();
  }

};

int main() { 
  return 0;
}
