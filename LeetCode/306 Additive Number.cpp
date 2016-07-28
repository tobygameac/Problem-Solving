class Solution {
 
 public:
  
  std::string Add(const std::string &a, const std::string &b) {
    std::string c;
    int i = a.length(), j = b.length();
    int carry = 0;
    while (i || j) {
      int digit = carry;
      if (i) {
        digit += a[--i] - '0';
      }
      if (j) {
        digit += b[--j] - '0';
      }
      carry = digit / 10;
      digit = digit % 10;
      c += (digit + '0');
    }
    if (carry) {
      c += '1';
    }
    std::reverse(c.begin(), c.end());
    return c;
  }

  bool IsAdditiveNumber(std::string &a, std::string &b, std::string num) {
    std::string c = Add(a, b);
    if (c.length() <= num.length()) {
      if (num.substr(0, c.length()) == c) {
        if (c.length() == num.length()) {
          return true;
        }
        return IsAdditiveNumber(b, c, num.substr(c.length()));
      }
    }
    return false;
  }

  bool isAdditiveNumber(string num) {
    if (num == "") {
      return false;
    }
    for (int i = 0; num[i]; ++i) {
      std::string a = num.substr(0, i + 1);
      if (a[0] == '0' && a[1]) {
        break;
      }
      for (int j = i + 1; num[j]; ++j) {
        std::string b = num.substr(i + 1, j - i);
        if (b[0] == '0' && b[1]) {
          break;
        }
        if (IsAdditiveNumber(a, b, num.substr(j + 1))) {
          return true;
        }
      }
    }
    return false;
  }

};
