class Solution {
  
 public:
 
  bool Search(std::vector<std::vector<char> > &board, std::string &word, int r, int c, const int R, const int C, int index) {
    if (!word[index]) {
      return true;
    }

    if ((r < 0) || (c < 0) || (r >= R) || (c >= C) || (board[r][c] != word[index])) {
      return false;
    }

    static const int dr[4] = {0, 1, 0, -1};
    static const int dc[4] = {1, 0, -1, 0};

    char real_c = board[r][c];
    board[r][c] = 0;

    for (size_t d = 0; d < 4; ++d) {
      if (Search(board, word, r + dr[d], c + dc[d], R, C, index + 1)) {
        board[r][c] = real_c;
        return true;
      }
    }

    board[r][c] = real_c;

    return false;
  }

  bool exist(std::vector<std::vector<char> > &board, std::string word) {
    const size_t R = board.size();
    if (!R) {
      return word == "";
    }
    const size_t C = board[0].size();
    for (size_t r = 0; r < R; ++r) {
      for (size_t c = 0; c < C; ++c) {
        if (Search(board, word, r, c, R, C, 0)) {
          return true;
        }
      }
    }
    return false;
  }
};
