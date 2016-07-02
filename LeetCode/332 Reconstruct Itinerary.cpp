class Solution {
 
 public:
  
  void Solve(std::string current, int total, std::unordered_map<std::string, std::vector<std::string> > &targets, std::vector<std::string> &path, std::vector<std::vector<std::string> > &solutions) {
    if (solutions.size()) {
      return;
    }
    if (path.size() > total) {
      solutions.push_back(path);
      return;
    }
    for (std::string &target : targets[current]) {
      if (target != "") {
        std::string real_target = target;
        target = "";
        path.push_back(real_target);
        Solve(real_target, total, targets, path, solutions);
        if (solutions.size()) {
          break;
        }
        path.pop_back();
        target = real_target;
      }
    }
  }

  std::vector<std::string> findItinerary(std::vector<std::pair<std::string, std::string> > tickets) {
    std::unordered_map<std::string, std::vector<std::string> > targets;
    for (const auto &ticket : tickets) {
      targets[ticket.first].push_back(ticket.second);
    }
    for (auto &it : targets) {
      std::sort(it.second.begin(), it.second.end());
    }
    std::vector<std::vector<std::string> > solutions;
    std::string starting_point = "JFK";
    std::vector<std::string> path(1, starting_point);
    Solve(starting_point, tickets.size(), targets, path, solutions);
    return solutions[0];
  }

};
