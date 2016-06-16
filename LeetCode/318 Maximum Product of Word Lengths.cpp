class Solution {
 
 public:
  
  int maxProduct(std::vector<std::string> &words) {
    const size_t N = words.size();
    std::vector<size_t> word_length(N);
    std::vector<size_t> mask(N, 0);
    for (size_t i = 0; i < N; ++i) {
      word_length[i] = words[i].length();
      for (char c : words[i]) {
        mask[i] |= 1 << (c - 'a' + 1);
      }
    }
    size_t answer = 0;
    for (size_t i = 0; i < N; ++i) {
      for (size_t j = i + 1; j < N; ++j) {
        if (!(mask[i] & mask[j])) {
          answer = std::max(answer, word_length[i] * word_length[j]);
        }
      }
    }
    return answer;
  }

};
