class Solution {
 
 public:
  
  int singleNumber(std::vector<int> &nums) {
    int a = 0, b = 0;
    for (int n : nums) {
      for (int bit = 0; bit < 32; ++bit) {
        int mask = 1 << bit;
        if (n & mask) {
          if (a & mask) {
            a ^= mask;
          } else if (b & mask) {
            a ^= mask;
            b ^= mask;
          } else {
            b ^= mask;
          }
        }
      }
    }
    return b;
  }

};

// 00
// 01
// 10
// 00
