class Solution {
 
 public:
   
  int findNthDigit(int n) {
    --n;
    long long current_head = 1, digits = 1, nums_count = 9;
    while (n > nums_count * digits) {
      n = n - nums_count * digits;
      current_head = current_head * 10;
      nums_count = nums_count * 10;
      digits = digits + 1;
    }
    long long target_num = current_head + (n / digits);
    long long target_digit = n % digits;
    return std::to_string(target_num)[target_digit] - '0';
  }

};
