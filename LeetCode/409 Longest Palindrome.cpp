class Solution {
 
 public:
   
  int longestPalindrome(string s) {
    size_t count[256] = {};
    for (char c : s) {
      ++count[c];
    }
    bool has_odd = false;
    size_t sum = 0;
    for (size_t i = 0; i < 256; ++i) {
      has_odd = has_odd || (count[i] & 1);
      sum = sum + count[i] - (count[i] & 1);
    }
    return sum + has_odd;
  }

};
