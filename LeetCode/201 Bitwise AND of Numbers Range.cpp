class Solution {

 public:
  
  int rangeBitwiseAnd(int m, int n) {
    int gap = n - m;
    for (int bit = 0, mask = 1; bit < 31 && mask < gap; ++bit, mask <<= 1) {
      if (m & mask) {
        m ^= mask;
      }
    }
    return m & n;
  }

};
