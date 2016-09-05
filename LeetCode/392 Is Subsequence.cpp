class Solution {
 
 public:
  
  bool IsSubsequence(std::string &s, std::string &t, int i, int j) {
    if (!s[i]) {
      return true;
    }
    for (; t[j]; ++j) {
      if (s[i] == t[j]) {
        if (IsSubsequence(s, t, i + 1, j + 1)) {
          return true;
        }
      }
    }
    return false;
  }

  bool isSubsequence(std::string &s, std::string &t) {
    return IsSubsequence(s, t, 0, 0);
  }

};
