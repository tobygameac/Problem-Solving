#include <cstdio>
#include <vector>

class Solution {
 public:
  int totalNQueens(int n) {
    int answer = 0;
    solve_n_queens(0, n, 0, 0, 0, answer);
    return answer;
  }

  void solve_n_queens(int r, int n, int check_c, int check_d1, int check_d2, int &answer) {
    if (r == n) {
      ++answer;
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
        solve_n_queens(r + 1, n, check_c, check_d1, check_d2, answer);
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
