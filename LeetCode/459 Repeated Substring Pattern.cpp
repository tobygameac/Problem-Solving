class Solution {

 public:

  bool repeatedSubstringPattern(std::string str) {
    const size_t N = str.length();
    for (size_t times = 2; times <= N; ++times) {
      if (!(N % times)) {
        size_t substr_length = N / times;
        for (size_t i = 0; i < substr_length; ++i) {
          char c = str[i];
          for (size_t t = 1; t < times; ++t) {
            if (str[t * substr_length + i] != c) {
              return false;
            }
          }
        }
      }
    }
    return N >= 2;
  }

};
