class Solution {
 
 public:
  
  long long Divide(long long dividend, long long divisor) {
    if (!dividend) {
      return 0;
    }
    if (!divisor) {
      return INT_MAX;
    }
    if (divisor == 1) {
      return dividend;
    }
    if (divisor < 0) {
      return -Divide(dividend, -divisor);
    }
    if (dividend < 0) {
      return -Divide(-dividend, divisor);
    }
    std::vector<long long> divisors{1, divisor};
    while (divisors.back() < dividend) {
      divisors.push_back(divisors.back() + divisors.back());
    }
    long long ans = 0;
    for (int bit = divisors.size() - 1; bit >= 0; --bit) {
      if (dividend >= divisors[bit]) {
        dividend -= divisors[bit];
        ans |= (1LL << bit);
      }
    }
    return ans >> 1;
  }

  int divide(long long dividend, long long divisor) {
    return std::min(Divide(dividend, divisor), (long long)INT_MAX);
  }

};
