#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <vector>

std::string GetPrefix(const std::string &a, const std::string &b) {
  std::string prefix;
  for (int i = 0; a[i] && b[i]; ++i) {
    if (a[i] == b[i]) {
      prefix += a[i];
    } else {
      break;
    }
  }
  return prefix;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int N;
    scanf("%d", &N);

    std::vector<std::string> words;

    for (int i = 0; i < N; ++i) {
      char buf[1111];
      scanf("%s", buf);
      std::string word(buf);
      std::reverse(word.begin(), word.end());
      words.push_back(word);
    }

    std::sort(words.begin(), words.end());

    std::set<std::string> used_prefix;

    while (words.size() > 1) {
      int max_length = 0, position = 0;
      std::string max_prefix;
      for (int i = 0; (i + 1) < words.size(); ++i) {
        std::string prefix = GetPrefix(words[i], words[i + 1]);
        if (prefix.length() > max_length) {
          max_length = prefix.length();
          position = i;
          max_prefix = prefix;
        }
      }

      if (max_length <= 0) {
        break;
      }

      words.erase(words.begin() + position + 1);
      words.erase(words.begin() + position);

      while (max_prefix.length() && (used_prefix.find(max_prefix) != used_prefix.end())) {
        max_prefix.pop_back();
      }

      if (max_prefix.length()) {
        used_prefix.insert(max_prefix);
      }
    }

    printf("Case #%d: %d\n", t, used_prefix.size() * 2);
  }
  return 0;
}
