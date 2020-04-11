#include <iostream>
#include <string>
#include <vector>

std::string FindPattern(const std::vector<std::string> &P)
{
  std::string pre = "", post = "";
  std::string subs;
  for (const std::string &s : P) {
    int last = -1;
    for (int i = 0; s[i]; ++i) {
      if (s[i] == '*') {
        if (last == -1) {
          std::string current_pre = s.substr(0, i);
          if (current_pre.length() > pre.length()) {
            std::swap(current_pre, pre);
          }
          if (pre.substr(0, current_pre.length()) != current_pre) {
            return "*";
          }
        } else {
          subs += s.substr(last + 1, i - last - 1);
        }
        last = i;
      }
    }

    std::string current_post = s.substr(last + 1);
    if (current_post.length() > post.length()) {
      std::swap(current_post, post);
    }
    if (post.substr(post.length() - current_post.length()) != current_post) {
      return "*";
    }
  }

  return pre + subs + post;
}

int main()
{
  int T;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    std::cin >> N;
    std::vector<std::string> P(N);
    for (int i = 0; i < N; ++i) {
      std::cin >> P[i];
    }
    std::cout << "Case #" << t << ": " << FindPattern(P) << "\n";
  }
  return 0;
}
