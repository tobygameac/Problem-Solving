#include <vector>
#include <algorithm>

class Solution {
 public:
  int minPathSum(std::vector<std::vector<int> > &grid) {
    std::vector<std::vector<int> > ans(grid.size() + 1, std::vector<int>((grid.size() ? grid[0].size() : 0) + 1, 2e9));
    for (int r = 1; r <= grid.size(); ++r) {
      for (int c = 1; c <= grid[0].size(); ++c) {
        if (r == 1 && c == 1) {
          ans[r][c] = grid[r - 1][c - 1];
        } else {
          ans[r][c] = std::min(ans[r - 1][c], ans[r][c - 1]) + grid[r - 1][c - 1];
        }
      }
    }
    return ans.back().back();
  }
};

int main() {
  return 0;
}
