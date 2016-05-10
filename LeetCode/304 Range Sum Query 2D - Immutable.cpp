#include <cstdio>
#include <vector>

class NumMatrix {
 
 public:
  
  NumMatrix(std::vector<std::vector<int> > &matrix) {
    if (!matrix.size()) {
      return;
    }
    const size_t R = matrix.size();
    const size_t C = matrix[0].size();
    cummulative_sum = std::vector<std::vector<int> >(R + 1, std::vector<int>(C + 1));
    cummulative_sum[0][0] = 0;
    for (size_t r = 1; r <= R; ++r) {
      for (size_t c = 1; c <= C; ++c) {
        cummulative_sum[r][c] = cummulative_sum[r - 1][c] + cummulative_sum[r][c - 1] - cummulative_sum[r - 1][c - 1] + matrix[r - 1][c - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return cummulative_sum[row2 + 1][col2 + 1] - cummulative_sum[row2 + 1][col1] - cummulative_sum[row1][col2 + 1] +cummulative_sum[row1][col1];
  }
    
  std::vector<std::vector<int> > cummulative_sum;
};

int main() { 
  return 0;
}
