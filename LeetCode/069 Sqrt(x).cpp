class Solution {
 
 public:
  
  int mySqrt(int x) {
    size_t l = 0;
    size_t r = x;
    while (l < r) {
      size_t mid = (l + r) / 2;
      size_t sqr = mid * mid;
      if (sqr >= x) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l - (l * l != x);
  }

};
