#include <vector>
#include <string>

class Solution {
 public:
  int minDistance(std::string word1, std::string word2) {
    std::vector<std::vector<int> > path_count(word1.length() + 1, std::vector<int>(word2.length() + 1, 0));
    for (int i = 1; i <= word1.length(); ++i) {
      path_count[i][0] = i;
    }
    for (int i = 1; i <= word2.length(); ++i) {
      path_count[0][i] = i;
    }
    for (int i = 1; i <= word1.length(); ++i) {
      for (int j = 1; j <= word2.length(); ++j) {
        path_count[i][j] = std::min(path_count[i - 1][j], path_count[i][j - 1]) + 1;
        path_count[i][j] = std::min(path_count[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]), path_count[i][j]);
      }
    }
    return path_count[word1.length()][word2.length()];
  }
};

int main() {
  return 0;
}
