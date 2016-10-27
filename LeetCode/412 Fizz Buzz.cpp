class Solution {

 public:

  std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> results(n);
    for (int i = 1; i <= n; ++i) {
      std::string token;
      if (!(i % 3)) {
        token += "Fizz";
      }
      if (!(i % 5)) {
        token += "Buzz";
      }
      if (token == "") {
        token = std::to_string(i);
      }
      results[i - 1] = token;
    }
    return results;
  }

};
