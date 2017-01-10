class Solution {
 
 public:
  
  int islandPerimeter(std::vector<std::vector<int> > &grid) {
    const int D_R[4] = {1, 0, -1, 0};
    const int D_C[4] = {0, 1, 0, -1};

    size_t count = 0;

    const size_t R = grid.size();
    for (int r = 0; r < R; ++r) {
      const size_t C = grid[0].size();
      for (int c = 0; c < C; ++c) {
        if (grid[r][c]) {
          for (size_t d = 0; d < 4; ++d) {
            int neighbor_r = r + D_R[d];
            int neighbor_c = c + D_C[d];
            if ((neighbor_r < 0) || (neighbor_r >= R) || (neighbor_c < 0) || (neighbor_c >= C) || !grid[neighbor_r][neighbor_c]) {
              ++count;
            }
          }
        }
      }
    }

    return count;
  }

};
