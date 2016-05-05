class Solution {
 
 public:
  
  int romanToInt(std::string s) {
    const size_t TYPE = 13;
    const static std::string PATTERNS[TYPE] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    const static int VALUES[TYPE] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    int ans = 0;

    for (size_t i = 0; s[i];) {
      for (int t = TYPE - 1; t >= 0; --t) {
        bool found = true;
        for (size_t j = 0; found && PATTERNS[t][j]; ++j) {
          found = (s[i + j] == PATTERNS[t][j]);
        }
        if (found) {
          ans += VALUES[t];
          i += PATTERNS[t].length();
          break;
        }
      }
    }

    return ans;
  }

};
