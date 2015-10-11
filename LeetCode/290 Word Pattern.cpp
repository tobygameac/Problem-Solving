#include <string>
#include <map>
#include <sstream>

class Solution {
 public:
  bool wordPattern(std::string pattern, std::string str) {
    std::map<std::string, char> string_mapping;
    bool used[255] = {};
    std::istringstream ss(str);
    std::string token;
    for (int i = 0; i < pattern.size(); ++i) {
      ss >> token;
      if (string_mapping.find(token) == string_mapping.end()) {
        if (!used[pattern[i]]) {
          string_mapping[token] = pattern[i];
          used[pattern[i]] = true;
        } else {
          return false;
        }
      } else if (string_mapping[token] != pattern[i]) {
        return false;
      }
    }
    while (ss >> token) {
      return false;
    }
    return true;
  }
};

int main() {
  return 0;
}
