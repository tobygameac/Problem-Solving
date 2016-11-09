class Solution {

 public:

  int arrangeCoins(int n) {
    unsigned l = sqrt(2U * n);
    unsigned need = l * (l + 1) / 2;
    return l - (need > n);
  }

};
