class Solution {

 public:

  int fourSumCount(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C, std::vector<int> &D) {
    std::unordered_map<int, size_t> count;
    for (int c : C) {
      for (int d : D) {
        ++count[c + d];
      }
    }
    size_t ans = 0;
    for (int a : A) {
      for (int b : B) {
        ans += count[-(a + b)];
      }
    }
    return ans;
  }

};
