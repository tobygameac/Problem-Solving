#include <vector>
#include <string>
#include <algorithm>

class Solution {
 public:
  static const int C1 = 17, C2 = 23;
  static const int MOD = 1e4 + 7;

  int rolling_hash_value(const std::vector<int> &hash, const std::vector<int> &c_value, int l, int r) {
    return (hash[r] - (hash[l - 1] * c_value[r - l + 1]) % MOD + MOD) % MOD;
  }

  std::string longestPalindrome(std::string s) {
    std::vector<int> c1_value(s.length() + 1);
    std::vector<int> c2_value(s.length() + 1);
    for (int i = 0; i <= s.length(); ++i) {
      c1_value[i] = i ? ((c1_value[i - 1] * C1) % MOD) : 1;
      c2_value[i] = i ? ((c2_value[i - 1] * C2) % MOD) : 1;
    }

    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());

    std::vector<int> hash1(s.length() + 1), hash2(s.length() + 1);
    std::vector<int> reversed_hash1(s.length() + 1), reversed_hash2(s.length() + 1);
    for (int i = 0; i <= s.length(); ++i) {
      hash1[i] = i ? ((s[i - 1] + (hash1[i - 1] * C1) % MOD) % MOD) : 0;
      hash2[i] = i ? ((s[i - 1] + (hash2[i - 1] * C2) % MOD) % MOD) : 0;

      reversed_hash1[i] = i ? ((reversed_s[i - 1] + (reversed_hash1[i - 1] * C1) % MOD) % MOD) : 0;
      reversed_hash2[i] = i ? ((reversed_s[i - 1] + (reversed_hash2[i - 1] * C2) % MOD) % MOD) : 0;
    }

    int max_palindrome_length = 1;
    std::string longest_palindrome;
    for (int i = 1; i <= s.length(); ++i) {
      int l = i - (max_palindrome_length / 2);
      int r = i + (max_palindrome_length / 2);
      int reversed_l = s.length() - r + 1;
      int reversed_r = s.length() - l + 1;
      while (l > 0 && r <= s.length()
        && rolling_hash_value(hash1, c1_value, l, r) == rolling_hash_value(reversed_hash1, c1_value, reversed_l, reversed_r) 
        && rolling_hash_value(hash2, c2_value, l, r) == rolling_hash_value(reversed_hash2, c2_value, reversed_l, reversed_r)) {
        longest_palindrome = s.substr(l - 1, r - l + 1);
        max_palindrome_length += 2;
        l = i - (max_palindrome_length / 2);
        r = i + (max_palindrome_length / 2);
        reversed_l = s.length() - r + 1;
        reversed_r = s.length() - l + 1;
      }
    }
    --max_palindrome_length;
    for (int i = 1; i <= s.length(); ++i) {
      int l = i - (max_palindrome_length / 2) + 1;
      int r = i + (max_palindrome_length / 2);
      int reversed_l = s.length() - r + 1;
      int reversed_r = s.length() - l + 1;
      while (l > 0 && r <= s.length()
        && rolling_hash_value(hash1, c1_value, l, r) == rolling_hash_value(reversed_hash1, c1_value, reversed_l, reversed_r) 
        && rolling_hash_value(hash2, c2_value, l, r) == rolling_hash_value(reversed_hash2, c2_value, reversed_l, reversed_r)) {
        longest_palindrome = s.substr(l - 1, r - l + 1);
        max_palindrome_length += 2;
        l = i - (max_palindrome_length / 2) + 1;
        r = i + (max_palindrome_length / 2);
        reversed_l = s.length() - r + 1;
        reversed_r = s.length() - l + 1;
      }
    }
    return longest_palindrome;
  }
};

int main() {
  return 0;
}
