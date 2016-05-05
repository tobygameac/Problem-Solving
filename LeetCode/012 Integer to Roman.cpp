class Solution {
 
 public:
  
   std::string intToRoman(int num) {
    const size_t TYPE = 13;
    const static std::string PATTERNS[TYPE] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    const static int VALUES[TYPE] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    std::string ans;

    for (int t = TYPE - 1; t >= 0; --t) {
      while (num >= VALUES[t]) {
        ans += PATTERNS[t];
        num -= VALUES[t];
      }
    }

    return ans;
  }

};
