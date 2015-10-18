#include <vector>

class Solution {
 public:
  std::vector<int> spiralOrder(std::vector<std::vector<int> > &matrix) {
    std::vector<int> ans;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    int r = 0, c = 0, dir = 0;
    while (r >= 0 && r < matrix.size() && c >= 0 && c < matrix[r].size()) {
      ans.push_back(matrix[r][c]);
      matrix[r][c] = 2e9;
      int next_r = r + dr[dir];
      int next_c = c + dc[dir];
      int tried_times = 0;
      while (!(next_r >= 0 && next_r < matrix.size() && next_c >= 0 && next_c < matrix[r].size()) || matrix[next_r][next_c] == 2e9) {
        dir = (dir + 1) % 4;
        next_r = r + dr[dir];
        next_c = c + dc[dir];
        ++tried_times;
        if (tried_times > 4) {
          break;
        }
      }
      if (tried_times > 4) {
        break;
      }
      r = next_r;
      c = next_c;
    }
    return ans;
  }
};

int main() {
  return 0;
}
