#include <vector>

class Solution {
 public:
  int uniquePathsWithObstacles(std::vector<std::vector<int> > &obstacleGrid) {
    if (!obstacleGrid.size() || !obstacleGrid[0].size()) {
      return 0;
    }
    std::vector<std::vector<int> > ans(obstacleGrid.size() + 1, std::vector<int>(obstacleGrid[0].size() + 1, 0));

    for (int r = 1; r <= obstacleGrid.size(); ++r) {
      for (int c = 1; c <= obstacleGrid[0].size(); ++c) {
        if (obstacleGrid[r - 1][c - 1]) {
          continue;
        }
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
