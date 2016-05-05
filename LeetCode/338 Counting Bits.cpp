class Solution {
 
 public:
  
  size_t CountBits(int n) {
    size_t count = 0;
    while (n) {
      ++count;
      n &= (n - 1);
    }
    return count;
  }

  std::vector<int> countBits(int num) {
    std::vector<int> answer(num + 1);
    for (int i = 0; i <= num; ++i) {
      answer[i] = CountBits(i);
    }
    return answer;
  }
};
