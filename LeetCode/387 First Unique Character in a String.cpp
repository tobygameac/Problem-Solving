class Solution {
 
 public:
  
  int firstUniqChar(std::string s) {
    int count[26] = {}, pos[26];
    for (int i = 0; s[i]; ++i) {
      ++count[s[i] - 'a'];
      pos[s[i] - 'a'] = i;
    }
    int first = 2e9;
    for (int i = 0; i < 26; ++i) {
      if (count[i] == 1) {
        first = std::min(first, pos[i]);
      }
    }
    return (first == 2e9) ? -1 : first;
  }

};
