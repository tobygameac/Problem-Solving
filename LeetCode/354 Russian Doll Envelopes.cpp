// Too slow
class Solution {
 
 public:

  int maxEnvelopes(std::vector<std::pair<int, int> > &envelopes) {
    std::vector<std::pair<int, int> > dolls = envelopes;
    const size_t N = dolls.size();
    
    for (size_t i = 0; i < N; ++i) {
      dolls[i].second = -1 * dolls[i].second;
    }
    std::sort(dolls.begin(), dolls.end());
    for (size_t i = 0; i < N; ++i) {
      dolls[i].second = -1 * dolls[i].second;
    }

    std::map<int, int> width_count_map;
    for (size_t i = 0, count = 1; i < N; ++i, ++count) {
      width_count_map[dolls[i].first] = count;
    }
    std::vector<int> width_count(N);
    for (size_t i = 0; i < N; ++i) {
      size_t r = width_count_map[dolls[i].first];
      while (i < r) {
        width_count[i++] = r;
      }
      --i;
    }
    std::vector<int> maximum_possible(N, 1);
    int ans = 0;
    for (size_t i = 0; i < N; ++i) {
      for (size_t j = width_count[i]; j < N; ++j) {
        if (dolls[j].second > dolls[i].second) {
          maximum_possible[j] = std::max(maximum_possible[j], maximum_possible[i] + 1);
        } else {
          j = width_count[j] - 1;
        }
      }
      ans = std::max(ans, maximum_possible[i]);
    }
    return ans;
  }

};
