class Solution {
 
 public:
  
  void GenerateParenthesis(std::string current_s, int l, int need, std::vector<std::string> &ans) {
    if (!need) {
      if (!l) {
        ans.push_back(current_s);
      }
      return;
    }
    GenerateParenthesis(current_s + "(", l + 1, need - 1, ans);
    if (l) {
      GenerateParenthesis(current_s + ")", l - 1, need - 1, ans);
    }
  }

  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> ans;
    GenerateParenthesis("", 0, n * 2, ans);
    return ans;
  }

};
