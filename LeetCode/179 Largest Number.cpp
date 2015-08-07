#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  static string IntegerToString(int n) {
    if (!n) {
      return "0";
    }
    string str;
    while (n) {
      str += (n % 10) + '0';
      n /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
  }

  static bool Cmp(int a, int b) {
    string a_str = IntegerToString(a), b_str = IntegerToString(b);
    return (a_str + b_str) > (b_str + a_str);
  }

  string largestNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), Cmp);
    string ans;
    for (int i = 0; i < nums.size(); ++i) {
      ans += IntegerToString(nums[i]);
    }
    while (ans.length() > 1 && ans[0] == '0') {
      ans = ans.substr(1);
    }
    return ans;
  }
};

int main() {
  return 0;
}
