class Solution {
 
 public:
    
  std::vector<std::string> readBinaryWatch(int num) {
    const size_t SIZE = 10;
    std::vector<char> bits(SIZE, 0);
    for (size_t i = 1; (i <= num) && (i <= SIZE); ++i) {
      bits[SIZE - i] = 1;
    }
    std::vector<std::string> answer;
    do {
      size_t h = 0, m = 0;
      for (size_t i = 0; i < 4; ++i) {
        h = (h * 2) + bits[i];
      }
      for (size_t i = 4; i < SIZE; ++i) {
        m = (m * 2) + bits[i];
      }
      if (h < 12 && m < 60) {
        answer.push_back(std::to_string(h) + ":" + ((m < 10) ? "0" : "") + std::to_string(m));
      }
    } while (std::next_permutation(bits.begin(), bits.end()));
    return answer;
  }

};
