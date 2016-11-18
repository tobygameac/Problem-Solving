class Solution {
 
 public:
  
  std::vector<int> findRightInterval(std::vector<Interval> &intervals) {
    const size_t N = intervals.size();
    std::vector<std::pair<int, size_t> > starts(N);
    for (size_t i = 0; i < N; ++i) {
      starts[i] = std::make_pair(intervals[i].start, i);
    }
    std::sort(starts.begin(), starts.end());
    std::vector<int> rights(N);
    for (size_t i = 0; i < N; ++i) {
      size_t target_index = std::lower_bound(starts.begin(), starts.end(), std::make_pair(intervals[i].end, 0U)) - starts.begin();
      rights[i] = (target_index >= N) ? -1 : starts[target_index].second;
    }
    return rights;
  }

};
