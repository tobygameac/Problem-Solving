#include <vector>

class Solution {
 public:
  int maximalRectangle(std::vector<std::vector<char> > &matrix) {
    if (!matrix.size() || !matrix[0].size()) {
      return 0;
    }

    std::vector<std::vector<int> > left_area_count(matrix.size());
    for (int r = 0; r < matrix.size(); ++r) {
      left_area_count[r] = std::vector<int>(matrix[r].size());
      for (int c = 0; c < matrix[r].size(); ++c) {
        if (matrix[r][c] == '1') {
          left_area_count[r][c] = 1 + (c ? left_area_count[r][c - 1] : 0);
        } else {
          left_area_count[r][c] = 0;
        }
      }
    }

    int max_area = 0;
    for (int c = 0; c < matrix[0].size(); ++c) {
      for (int target_width = 1; target_width <= c + 1; ++target_width) {
        int area = 0;
        bool no_larger_size = true;
        for (int r = 0; r < matrix.size(); ++r) {
          if (left_area_count[r][c] >= target_width) {
            area += target_width;
            max_area = std::max(area, max_area);
            no_larger_size = false;
          } else {
            area = 0;
          }
        }
        if (no_larger_size) {
          break;
        }
      }
    }
    return max_area;
  }
};

int main() {
  return 0;
}
