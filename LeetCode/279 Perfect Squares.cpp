class Solution {
 
 public:
  
  int numSquares(int n) {
    static std::vector<size_t> num_squares(1, 0);
    int last_n = num_squares.size() - 1;
    while (num_squares.size() <= n) {
      num_squares.push_back(2e9);
    }
    for (size_t i = last_n; i <= n; ++i) {
      for (size_t j = 1; j * j <= i; ++j) {
        num_squares[i] = std::min(num_squares[i], 1 + num_squares[i - j * j]);
      }
    }
    return num_squares[n];
  }

};
