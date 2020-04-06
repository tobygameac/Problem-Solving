#include <iostream>
#include <string>

void AppendAndMinusOne(std::string &s)
{
  int l = -1, r = -1;
  for (int i = 0; ; ++i) {
    if ((s[i] >= '1') && (s[i] <= '9')) {
      if (l == -1) {
        l = i;
      }
      r = i;
      s[i] -= 1;
    } else if (l != -1) {
      s.insert(r + 1, ")");
      s.insert(l, "(");
      l = r = -1;
    } else if (!s[i]) {
      break;
    }
  }
}

int main()
{
  int T;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    std::string s, original_s;
    std::cin >> s;
    original_s = s;
    for (int i = 0; i < 10; ++i) {
      AppendAndMinusOne(s);
    }
    int digit_index = 0;
    for (int i = 0; s[i]; ++i) {
      if (s[i] == '0') {
        s[i] = original_s[digit_index++];
      }
    }
    std::cout << "Case #" << t << ": " << s << "\n";
  }
  return 0;
}
