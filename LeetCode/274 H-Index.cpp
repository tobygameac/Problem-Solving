class Solution {
 
 public:
  
  int hIndex(std::vector<int> &citations) {
    const size_t N = citations.size();
    std::vector<int> count(N + 1);
    for (int citation : citations) {
      ++count[(citation > N) ? N : citation];
    }
    for (int i = N - 1; i >= 0; --i) {
      count[i] += count[i + 1];
    }
    for (int i = N; i >= 0; --i) {
      if (count[i] >= i) {
        return i;
      }
    }
    return 0;
  }

};
