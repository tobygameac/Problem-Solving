#include <vector>

class Solution {
 public:
  std::vector<std::vector<int> > generateMatrix(int n) {
    if (!n) {
      return std::vector<std::vector<int> >();
    }
    std::vector<std::vector<int> > ans(n, std::vector<int>(n, 0));
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    int r = 0, c = 0, dir = 0;
    int num = 1;
    while (true) {
      ans[r][c] = num++;
      if (num > n * n) {
        break;
      }
      int next_r = r + dr[dir];
      int next_c = c + dc[dir];
      while (!(next_r >= 0 && next_r < n && next_c >= 0 && next_c < n) || ans[next_r][next_c]) {
        dir = (dir + 1) % 4;
        next_r = r + dr[dir];
        next_c = c + dc[dir];
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
