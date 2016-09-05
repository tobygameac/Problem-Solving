class Solution {
 
 public:
  
  std::string decodeString(std::string s) {
    size_t times = 0;
    std::string result;
    for (int i = 0, j; s[i]; ++i) {
      if (s[i] == '[') {
        int not_balance = 1;
        for (j = i + 1; not_balance; ++j) {
          not_balance += (s[j] == '[');
          not_balance -= (s[j] == ']');
        }
        --j;
        std::string token = decodeString(s.substr(i + 1, (j - 1) - (i + 1) + 1));
        while (times) {
          result += token;
          --times;
        }
        i = j;
      } else if (isdigit(s[i])) {
        times = times * 10 + s[i] - '0';
      } else {
        result += s[i];
      }
    }
    return result;
  }

};
