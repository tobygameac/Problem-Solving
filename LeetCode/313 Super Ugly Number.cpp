class Solution {
 
 public:
  
  int nthSuperUglyNumber(int n, std::vector<int> &primes) {
    size_t prime_count = primes.size();
    std::vector<size_t> last_indices(prime_count, 0);
    std::vector<int> ugly_numbers(n, 1);
    for (size_t i = 1; i < n; ++i) {
      size_t target_prime_index;
      int ugly_number;
      for (size_t j = 0; j < prime_count; ++j) {
        while (ugly_numbers[last_indices[j]] * primes[j] <= ugly_numbers[i - 1]) {
          ++last_indices[j];
        }
        int new_ugly_number = ugly_numbers[last_indices[j]] * primes[j];
        if (!j || new_ugly_number < ugly_number) {
          ugly_number = new_ugly_number;
          target_prime_index = j;
        }
      }
      ugly_numbers[i] = ugly_number;
    }
    return ugly_numbers[n - 1];
  }

};
