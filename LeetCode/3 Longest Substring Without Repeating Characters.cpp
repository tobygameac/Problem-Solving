#include <string>

using std::string;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    for (int i = 0; s[i]; ++i) {
      int length = 0;
      bool rec[256] = {};
      for (int j = i; s[j]; ++j) {
        if (rec[s[j]]) {
          break;
        }
        ++rec[s[j]];
        ++length;
      }
      maxLength = length > maxLength ? length : maxLength;
    }
    return maxLength;
  }
};

int main() {
  return 0;
}
