class Solution {
 
 public:
  
  void solve(std::vector<std::vector<char> > &board) {
    const size_t R = board.size();
    if (!R) {
      return;
    }
    const size_t C = board[0].size();
    const int dr[4] = {0, 1, 0, -1};
    const int dc[4] = {1, 0, -1, 0};
    for (size_t r = 0; r < R; ++r) {
      for (size_t c = 0; c < C; ++c) {
        if (!r || !c || ((r + 1) == R) || ((c + 1) == C)) {
          if (board[r][c] == 'O') {
            std::queue<std::pair<size_t, size_t> > q;
            q.push(std::make_pair(r, c));
            board[r][c] = '1';
            while (!q.empty()) {
              std::pair<size_t, size_t> current = q.front();
              q.pop();
              for (size_t d = 0; d < 4; ++d) {
                int new_r = current.first + dr[d];
                int new_c = current.second + dc[d];
                if (new_r >= 0 && new_r < R && new_c >= 0 && new_c < C && board[new_r][new_c] == 'O') {
                  q.push(std::make_pair(new_r, new_c));
                  board[new_r][new_c] = '1';
                }
              }
            }
          }
        }
      }
    }
    for (std::vector<char> &row : board) {
      for (char &c : row) {
        c = (c == '1') ? 'O' : 'X';
      }
    }
  }

};
