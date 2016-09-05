class Solution {
 
 public:
  
  void LexicalOrder(int n, const int MAX_N, std::vector<int> &ans) {
    if (n) {
      ans.push_back(n);
    }
    for (int digit = !n; digit < 10; ++digit) {
      int next_n = n * 10 + digit;
      if (next_n > MAX_N) {
        return;
      }
      LexicalOrder(next_n, MAX_N, ans);
    }
  }

  std::vector<int> lexicalOrder(int n) {
    std::vector<int> ans;
    LexicalOrder(0, n, ans);
    return ans;
  }

};
