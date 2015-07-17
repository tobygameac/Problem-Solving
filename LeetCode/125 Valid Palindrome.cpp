#include <string>
#include <cctype>

using std::string;

class Solution {
 public:
  bool isPalindrome(string s) {
    for (int l = 0, r = s.length() - 1; l < r; ) {
      if (!isalnum(s[l])) {
        ++l;
        continue;
      }
      if (!isalnum(s[r])) {
        --r;
        continue;
      }
      if (tolower(s[l]) != tolower(s[r])) {
        return false;
      }
      ++l;
      --r;
    }
    return true;
  }
};

int main() {
  return 0;
}
