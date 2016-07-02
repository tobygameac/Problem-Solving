class Solution {
 
 public:

  std::vector<int> countBits(int num) {
    std::vector<int> bits(num + 1);
    for (int i = 1; i <= num; ++i) {
      bits[i] = bits[i - 1] + 1;
      int carry = 1;
      while ((i - 1) & carry) {
        --bits[i];
        carry <<= 1;
      }
    }
    return bits;
  }

};

class Solution {
 
 public:

  std::vector<int> countBits(int num) {
    std::vector<int> bits(num + 1);
    for (int b = 1; ; ++b) {
      int l = 1 << (b - 1);
      int r = 1 << b;
      for (int i = l; i < r && i <= num; ++i) {
        bits[i] = bits[i - l] + 1;
      }
      if (r > num) {
        break;
      }
    }
    return bits;
  }

};

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

