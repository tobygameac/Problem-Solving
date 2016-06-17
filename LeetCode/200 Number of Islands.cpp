class Solution {
 
 public:
  
  void Fill(std::vector<std::vector<char> > &grid, int r, int c, const int R, const int C) {
    if (r < 0 || c < 0 || r >= R || c >= C) {
      return;
    }
    if (grid[r][c] == '0') {
      return;
    }
    grid[r][c] = '0';
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};
    for (size_t d = 0; d < 4; ++d) {
      Fill(grid, r + dr[d], c + dc[d], R, C);
    }
  }

  int numIslands(std::vector<std::vector<char> > &grid) {
    size_t ans = 0;
    const size_t R = grid.size();
    const size_t C = R ? grid[0].size() : 0;
    for (size_t r = 0; r < R; ++r) {
      for (size_t c = 0; c < C; ++c) {
        if (grid[r][c] == '1') {
          Fill(grid, r, c, R, C);
          ++ans;
        }
      }
    }
    return ans;
  }

};
