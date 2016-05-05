class Solution {
 
 public:
  
  string getHint(string secret, string guess) {
    size_t digit_count[10] = {};
    for (size_t i = 0; secret[i]; ++i) {
      ++digit_count[guess[i] - '0'];
    }
    size_t a = 0;
    size_t b = 0;
    for (size_t i = 0; secret[i]; ++i) {
      if (secret[i] == guess[i]) {
        ++a;
        --digit_count[secret[i] - '0'];
      }
    }
    for (size_t i = 0; secret[i]; ++i) {
      if (secret[i] != guess[i] && digit_count[secret[i] - '0']) {
        ++b;
        --digit_count[secret[i] - '0'];
      }
    }
    return std::to_string(a) + "A" + std::to_string(b) + "B";
  }

};
