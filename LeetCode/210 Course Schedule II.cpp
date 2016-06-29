class Solution {

 public:

  std::vector<int> findOrder(int num_courses, std::vector<std::pair<int, int> > &prerequisites) {
    std::vector<int> order;
    std::vector<std::vector<int> > unlock(num_courses);
    std::vector<int> need_count(num_courses, 0);
    for (std::pair<int, int> &p : prerequisites) {
      unlock[p.second].push_back(p.first);
      ++need_count[p.first];
    }
    for (int i = 0, target = 0; i < num_courses; ++i) {
      while (target < num_courses && need_count[target]) {
        ++target;
      }
      if (target == num_courses) {
        return std::vector<int>();
      }
      order.push_back(target);
      need_count[target] = -1;
      bool found_next_target = false;
      for (int j : unlock[target]) {
        --need_count[j];
        if (!need_count[j]) {
          target = j;
          found_next_target = true;
        }
      }
      if (!found_next_target) {
        target = 0;
      }
    }
    return order;
  }

};
