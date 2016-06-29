class Solution {
 
 public:
  
  bool isPerfectSquare(int num) {
    long long l = 0, r = num + 1;
    while (l < r) {
      long long mid = (l + r) / 2;
      long long sqr = mid * mid;
      if (sqr == num) {
        return true;
      }
      if (sqr > num) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return (l * l) == num;
  }

};
