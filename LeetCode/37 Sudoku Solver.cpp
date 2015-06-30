#include <cstring>
#include <vector>

using std::vector;

class Solution {
 public:
  const static int SUDOKU_SIZE = 9;
  const static int GRID_SIZE = 3;
  
  bool checkRow[SUDOKU_SIZE][SUDOKU_SIZE];
  bool checkColumn[SUDOKU_SIZE][SUDOKU_SIZE];
  bool checkGrid[GRID_SIZE][GRID_SIZE][SUDOKU_SIZE];

  bool done;

  void fillSudoku(vector<vector<char> >& board, int r, int c) {
    if (done) {
      return;
    }
    if (r == SUDOKU_SIZE) {
      done = 1;
      return;
    }
    if (c == SUDOKU_SIZE) {
      fillSudoku(board, r + 1, 0);
      return;
    }
    if (board[r][c] == '.') {
      for (int value = 0; !done && value < SUDOKU_SIZE; ++value) {
        if (checkRow[r][value] || checkColumn[c][value] || checkGrid[r / GRID_SIZE][c / GRID_SIZE][value]) {
          continue;
        }
        checkRow[r][value] = checkColumn[c][value] = checkGrid[r / GRID_SIZE][c / GRID_SIZE][value] = 1;
        board[r][c] = value + '0' + 1;
        fillSudoku(board, r, c + 1);
        if (!done) {
          board[r][c] = '.';
        }
        checkRow[r][value] = checkColumn[c][value] = checkGrid[r / GRID_SIZE][c / GRID_SIZE][value] = 0;
      }
    } else {
      fillSudoku(board, r, c + 1);
    }
  }

  void solveSudoku(vector<vector<char> >& board) {
    memset(checkRow, 0, sizeof(checkRow));
    memset(checkColumn, 0, sizeof(checkColumn));
    memset(checkGrid, 0, sizeof(checkGrid));

    for (int r = 0; r < board.size(); ++r) {
      for (int c = 0; c < board[r].size(); ++c) {
        if (board[r][c] != '.') {
          int value = board[r][c] - '0' - 1;
          checkRow[r][value] = checkColumn[c][value] = checkGrid[r / GRID_SIZE][c / GRID_SIZE][value] = 1;
        }
      }
    }

    done = false;
    fillSudoku(board, 0, 0);
  }
};

int main() {
  return 0;
}
