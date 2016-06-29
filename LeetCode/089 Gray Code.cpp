class Solution {
 
 public:
  
  std::vector<int> grayCode(int n) {
    const size_t N = 1 << n;
    std::vector<char> exist(N, 0);
    exist[0] = 1;
    std::vector<int> ans(N, 0);
    std::vector<int> mask(n);
    for (size_t i = 0; i < n; ++i) {
      mask[i] = 1 << i;
    }
    for (size_t i = 1; i < N; ++i) {
      for (int m : mask) {
        ans[i] = ans[i - 1] ^ m;
        if (!exist[ans[i]]) {
          exist[ans[i]] = 1;
          break;
        }
      }
    }
    return ans;
  }

};
