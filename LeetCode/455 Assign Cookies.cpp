class Solution {

 public:

  int findContentChildren(std::vector<int> &g, std::vector<int> &s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    const size_t N = g.size();
    size_t child_index = 0;
    for (int size : s) {
      if (child_index >= N) {
        break;
      }
      if (size >= g[child_index]) {
        ++child_index;
      } else {
        break;
      }
    }
    return child_index;
  }

};
