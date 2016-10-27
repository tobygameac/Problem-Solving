class Solution {

 public:

  std::string addStrings(std::string num1, std::string num2) {

    std::string result;

    int l1 = num1.length();
    int l2 = num2.length();
    int carry = 0;

    while (l1 || l2) {
      int digit = 0;
      if (l1) {
        digit += num1[--l1] - '0';
      }
      if (l2) {
        digit += num2[--l2] - '0';
      }
      digit = digit + carry;

      carry = digit / 10;
      digit = digit % 10;

      result += char(digit + '0');
    }

    if (carry) {
      result += '1';
    }

    std::reverse(result.begin(), result.end());

    return result;
  }

};
