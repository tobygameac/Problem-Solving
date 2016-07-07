class Solution {
 
 public:
    
  int lengthOfLongestSubstring(std::string s) {
    int count[256] = {};
    int length = 0;
    for (int l = 0, r = 0; s[r];) {
      r = std::max(l, r);
      while (s[r] && !count[s[r]]) {
        ++count[s[r++]];
      }
      length = std::max(length, r - l);
      --count[s[l++]];
    }
    return length;
  }

};
