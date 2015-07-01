#include <string>

using std::string;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    int l1 = haystack.length(), l2 = needle.length();
    for (int i = 0; i + l2 - 1 < l1; ++i) {
      bool found = true;
      for (int j = 0; j < l2 && found; ++j) {
        found = (haystack[i + j] == needle[j]);
      }
      if (found) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  return 0;
}
