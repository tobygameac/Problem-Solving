class Solution {
 
 public:
  
  bool wordBreak(std::string s, std::unordered_set<std::string> &unordered_dict) {
    const size_t N = s.length();
    std::vector<char> breakable(N + 1);
    breakable[0] = true;
    for (size_t i = 1; i <= N; ++i) {
      for (const std::string &word : unordered_dict) {
        const size_t L = word.length();
        if (i >= L) {
          breakable[i] |= breakable[i - L] && (s.substr(i - L, L) == word);
        }
      }
    }
    return breakable[N];
  }

};
