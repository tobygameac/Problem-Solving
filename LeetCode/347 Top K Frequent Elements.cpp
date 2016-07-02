class Solution {
 
 public:
  
  int Split(std::vector<std::pair<int, int> > &nums_and_counts, int l, int r) {
    int pivot = l + rand() % (r - l);
    std::swap(nums_and_counts[pivot], nums_and_counts[r - 1]);
    int target_index = l;
    for (int i = l; i < r - 1; ++i) {
      if (nums_and_counts[i].second > nums_and_counts[r - 1].second) {
        std::swap(nums_and_counts[i], nums_and_counts[target_index++]);
      }
    }
    std::swap(nums_and_counts[r - 1], nums_and_counts[target_index]);
    return target_index;
  }

  void Kth(std::vector<std::pair<int, int> > &nums_and_counts, int l, int r, int k) {
    int pivot = Split(nums_and_counts, l, r);
    if (pivot == k) {
      return;
    }
    if (pivot < k) {
      Kth(nums_and_counts, pivot + 1, r, k);
      return;
    }
    Kth(nums_and_counts, l, pivot, k);
  }

  std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> counts_map;
    for (int n : nums) {
      ++counts_map[n];
    }
    std::vector<std::pair<int, int> > nums_and_counts(counts_map.begin(), counts_map.end());
    Kth(nums_and_counts, 0, nums_and_counts.size(), k - 1);
    std::vector<int> answer;
    for (size_t i = 0; i < k; ++i) {
      answer.push_back(nums_and_counts[i].first);
    }
    return answer;
  }

};
