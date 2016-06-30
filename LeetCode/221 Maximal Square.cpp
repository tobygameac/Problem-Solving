class Solution {
 
 public:
 
  int maximalSquare(std::vector<std::vector<char> > &matrix) {
    const size_t R = matrix.size();
    if (!R) {
      return 0;
    }
    const size_t C = matrix[0].size();
    std::vector<std::vector<int> > length(R + 1, std::vector<int>(C + 1, 0));
    std::vector<std::vector<int> > height = length, width = length;
    for (size_t r = 1; r <= R; ++r) {
      for (size_t c = 1; c <= C; ++c) {
        if (matrix[r - 1][c - 1] == '1') {
          height[r][c] = 1 + height[r - 1][c];
          width[r][c] = 1 + width[r][c - 1];
        }
      }
    }
    int max_length = 0;
    for (size_t r = 1; r <= R; ++r) {
      for (size_t c = 1; c <= C; ++c) {
        if (matrix[r - 1][c - 1] == '1') {
          length[r][c] = std::min(length[r - 1][c - 1] + 1, std::min(width[r][c], height[r][c]));
          max_length = std::max(max_length, length[r][c]);
        }
      }
    }
    return max_length * max_length;
  }

};
