#include <vector>

class Solution {
 public:
  int uniquePaths(int m, int n) {      
    std::vector<std::vector<int> > ans(m + 1, std::vector<int>(n + 1, 0));
    for (int r = 1; r <= m; ++r) {
      for (int c = 1; c <= n; ++c) {
        if (r == 1 && c == 1) {
          ans[r][c] = 1;
        } else {
          ans[r][c] = ans[r - 1][c] + ans[r][c - 1];
        }
      }
    }
    return ans.back().back();
  }
};

int main() {
  return 0;
}
