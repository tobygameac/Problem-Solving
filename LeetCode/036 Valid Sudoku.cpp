#include <vector>

class Solution {
 public:
  bool isValidSudoku(std::vector<std::vector<char> > &board) {
    bool check_row[9][10] = {}, check_column[9][10] = {};
    bool check_grid[9][9][10] = {};
    for (int r = 0; r < board.size(); ++r) {
      for (int c = 0; c < board.size(); ++c) {
        int value = board[r][c] - '0';
        if (value >= 0 && value <= 9) {
          if (check_row[r][value]) {
            return false;
          }
          if (check_column[c][value]) {
            return false;
          }
          if (check_grid[r / 3][c / 3][value]) {
            return false;
          }
          check_row[r][value] = check_column[c][value] = check_grid[r / 3][c / 3][value] = true;
        }
      }
    }
    return true;
  }
};

int main() {
  return 0;
}
