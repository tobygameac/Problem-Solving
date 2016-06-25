class Solution {
 
 public:
  
  void Connect(TreeLinkNode *node, size_t depth, std::vector<TreeLinkNode *> &tails) {
    if (!node) {
      return;
    }
    Connect(node->left, depth + 1, tails);
    while (tails.size() <= depth) {
      tails.push_back(0);
    }
    if (!tails[depth]) {
      tails[depth] = node;
    } else {
      tails[depth]->next = node;
      tails[depth] = node;
    }
    Connect(node->right, depth + 1, tails);
  }

  void connect(TreeLinkNode *root) {
    std::vector<TreeLinkNode *> tails;
    Connect(root, 0, tails);
  }

};
