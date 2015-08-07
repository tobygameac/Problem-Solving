#include <cmath>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> not_prime;

  void build_table(int len) {
    if (len < 2) {
      len = 2;
    }
    if (len <= not_prime.size()) {
      return;
    }
    not_prime = vector<int>(len, 0);
    not_prime[0] = not_prime[1] = 1;
    for (int i = 2; i < not_prime.size(); ++i) {
      if (!not_prime[i]) {
        for (int j = i + i; j < not_prime.size(); j += i) {
          not_prime[j] = 1;
        }
      }
    }
  }

  int countPrimes(int n) {
    build_table(n);
    int prime_count = 0;
    for (int i = 2; i < n; ++i) {
      prime_count += !not_prime[i];
    }
    return prime_count;
  }

};

int main() {
  return 0;
}
