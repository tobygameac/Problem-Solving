class Solution {
 
 public:
  
  void Search(const std::string &s, int i, std::vector<int> &values, std::vector<std::string> &solutions) {
    if (values.size() > 4) {
      return;
    }

    if (!s[i]) {
      if (values.size() == 4) {
        solutions.push_back(std::to_string(values[0]) + "." + std::to_string(values[1]) + "." + std::to_string(values[2]) + "." + std::to_string(values[3]));
      }
      return;
    }

    int value = 0;
    while (s[i]) {
      value = value * 10 + (s[i] - '0');
      if (value > 255) {
        return;
      }
      values.push_back(value);
      Search(s, i + 1, values, solutions);
      values.pop_back();
      if (!value) {
        return;
      }
      ++i;
    }
  }

  std::vector<std::string> restoreIpAddresses(std::string s) {
    std::vector<int> values;
    std::vector<std::string> solutions;
    Search(s, 0, values, solutions);
    return solutions;
  }

};
