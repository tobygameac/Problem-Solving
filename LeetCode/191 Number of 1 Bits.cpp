#include <stdint.h>
#include <bitset>

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    // int ans = 0;
    // while (n) {
    //  ++ans;
    //  n &= (n - 1);
    // }
    // return ans;
    return std::bitset<32>(n).count();
  }
};

int main() {
  return 0;
}
