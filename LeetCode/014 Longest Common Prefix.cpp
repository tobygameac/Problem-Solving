#include <vector>
#include <string>

class Solution {
 public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    if (!strs.size()) {
      return "";
    }
    for (int i = 0; ; ++i) {
      for (int j = 0; j < strs.size(); ++j) {
        if (!strs[j][i] || (j && strs[j][i] != strs[j - 1][i])) {
          return strs[j].substr(0, i);
        }
      }
    }
  }
};

int main() {
  return 0;
}
