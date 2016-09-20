class Solution {
 
 public:
   
  std::string removeKdigits(std::string num, int k) {
    for (int i = 0; num[i + 1] && k; ++i) {
      if (num[i] > num[i + 1]) {
        num.erase(num.begin() + i);
        i -= (i ? 2 : 1);
        --k;
      }
    }
    num = num.substr(0, num.length() - k);
    int leading_zero = 0;
    while (num[leading_zero] == '0' && num[leading_zero]) {
      ++leading_zero;
    }
    num = num.substr(leading_zero);
    return (num == "") ? "0" : num;
  }
    
};
