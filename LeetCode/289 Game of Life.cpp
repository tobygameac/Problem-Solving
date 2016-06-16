class Solution {
 
 public:
  
  void gameOfLife(std::vector<std::vector<int>> &board) {
    const size_t R = board.size();
    if (!R) {
      return;
    }
    const size_t C = board[0].size();
    std::vector<std::vector<int>> old_board = board;
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        size_t lived = 0;
        for (int dr = -1; dr <= 1; ++dr) {
          for (int dc = -1; dc <= 1; ++dc) {
            int neighbor_r = r + dr;
            int neighbor_c = c + dc;
            if (neighbor_r >= 0 && neighbor_r < R && neighbor_c >= 0 && neighbor_c < C) {
              lived += old_board[neighbor_r][neighbor_c] == 1;
            }
          }
        }
        lived -= old_board[r][c] == 1;
        if (board[r][c]) {
          board[r][c] = (lived == 2) || (lived == 3);
        } else {
          board[r][c] = (lived == 3);
        }
      }
    }
  }

};
