class Solution {

 public:
  
  int numDecodings(string s) {
    const size_t N = s.length();
    if (!N) {
      return 0;
    }
    std::vector<int> ans(N + 2);
    ans[N] = ans[N + 1] = 1;
    for (int i = N - 1; i >= 0; --i) {
      ans[i] = (s[i] == '0') ? 0 : ans[i + 1];
      if ((i != (N - 1)) && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
        ans[i] = ans[i + 1] + ans[i + 2];
      }
    }

    return ans[0];
  }

};
