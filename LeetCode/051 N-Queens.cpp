#include <cstdio>
#include <vector>
#include <string>

class Solution {
 public:
  std::vector<std::vector<std::string> > solveNQueens(int n) {
    std::vector<std::vector<std::string> > answer;
    std::vector<std::string> state(n, std::string(n, '.'));
    solve_n_queens(0, n, state, 0, 0, 0, answer);
    return answer;
  }

  void solve_n_queens(int r, int n, std::vector<std::string> &state,
    int check_c, int check_d1, int check_d2,
    std::vector<std::vector<std::string> > &answer) {
    if (r == n) {
      answer.push_back(state);
      return;
    }

    for (int c = 0; c < n; ++c) {
      int mask_c = 1 << c;
      int mask_d1 = 1 << (r + c);
      int mask_d2 = 1 << (r - c + n);
      if (!(check_c & mask_c) && !(check_d1 & mask_d1) && !(check_d2 & mask_d2)) {
        check_c ^= mask_c;
        check_d1 ^= mask_d1;
        check_d2 ^= mask_d2;
        state[r][c] = 'Q';
        solve_n_queens(r + 1, n, state, check_c, check_d1, check_d2, answer);
        state[r][c] = '.';
        check_c ^= mask_c;
        check_d1 ^= mask_d1;
        check_d2 ^= mask_d2;
      }
    }
  }
};

int main() {
  return 0;
}
