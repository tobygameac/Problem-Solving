class Solution {
 
 public:
  
  void flatten(TreeNode *root) {
    if (!root) {
      return;
    }
    TreeNode *l = root->left;
    TreeNode *r = root->right;
    flatten(l);
    flatten(r);
    root->left = 0;
    while (l) {
      root->right = l;
      root = root->right;
      l = l->right;
    }
    root->right = r;
  }

};
