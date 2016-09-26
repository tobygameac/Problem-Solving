class Solution {
 
 public:
   
  std::string ToHex(unsigned num) {
    if (!num) {
      return "";
    }
    return ToHex(num / 16) + std::string(1, ((num % 16) < 10 ? '0' : ('a' - 10)) + (num % 16));
  }

  std::string toHex(int num) {
    if (!num) {
      return "0";
    }
    return ToHex(num);
  }

};
