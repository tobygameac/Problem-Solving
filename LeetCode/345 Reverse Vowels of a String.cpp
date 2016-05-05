class Solution {
 
 public:
  
  bool IsVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }

  std::string reverseVowels(std::string s) {
    std::vector<size_t> positions;

    for (size_t i = 0; s[i]; ++i) {
      if (IsVowel(s[i])) {
        positions.push_back(i);
      }
    }

    for (size_t i = 0; i < positions.size() / 2; ++i) {
      std::swap(s[positions[i]], s[positions[positions.size() - i - 1]]);
    }
    return s;
  }

};
