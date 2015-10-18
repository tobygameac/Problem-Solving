#include <vector>

class Solution {
 public:
  void setZeroes(std::vector<std::vector<int> > &matrix) {
    if (!matrix.size() || !matrix[0].size()) {
      return;
    }

    std::vector<int> zero_row(matrix.size(), 0);
    std::vector<int> zero_column(matrix[0].size(), 0);

    for (int r = 0; r < matrix.size(); ++r) {
      for (int c = 0; c < matrix[0].size(); ++c) {
        if (!matrix[r][c]) {
          zero_row[r] = zero_column[c] = 1;
        }
      }
    }

    for (int r = 0; r < matrix.size(); ++r) {
      for (int c = 0; c < matrix[0].size(); ++c) {
        if (zero_row[r] || zero_column[c]) {
          matrix[r][c] = 0;
        }
      }
    }
  }
};

int main() {
  return 0;
}
