#include <vector>

class Solution {
 public:
  bool searchMatrix(std::vector<std::vector<int> > &matrix, int target) {
    int row = matrix.size();
    int column = row ? matrix[0].size() : 0;

    int r = 0, c = column - 1;
    while (r < row && c >= 0) {
      if (matrix[r][c] == target) {
        return true;
      }
      if (matrix[r][c] > target) {
        --c;
      } else {
        ++r;
      }
    }
    return false;
  }
};

int main() {
  return 0;
}
