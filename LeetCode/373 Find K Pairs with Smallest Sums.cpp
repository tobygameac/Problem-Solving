class Solution {
 
 public:
    
  std::vector<std::pair<int, int> > kSmallestPairs(std::vector<int> &nums_1, std::vector<int> &nums_2, int k) {
    std::priority_queue<std::tuple<int, int, int> > q;
    const size_t N_1 = nums_1.size();
    const size_t N_2 = nums_2.size();
    for (size_t i = 0; i < N_1 && i < k; ++i) {
      for (size_t j = 0; j < N_2 && j < k; ++j) {
        if (q.size() == k && (nums_1[i] + nums_2[j]) >= std::get<0>(q.top())) {
          break;
        }
        q.push(std::make_tuple(nums_1[i] + nums_2[j], nums_1[i], nums_2[j]));
        if (q.size() > k) {
          q.pop();
        }
      }
    }
    std::vector<std::pair<int, int> > pairs;
    while (q.size()) {
      pairs.push_back(std::make_pair(std::get<1>(q.top()), std::get<2>(q.top())));
      q.pop();
    }
    return pairs;
  }

};
