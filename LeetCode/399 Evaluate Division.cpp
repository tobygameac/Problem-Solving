class Solution {
 
 public:
   
  void CalcEquation(std::string now, const std::string &target, double current_value, double &answer, bool &solved, std::set<std::string> &visited, std::map<std::string, std::vector<std::string> > &neighbors, std::map<std::string, std::map<std::string, double> > &weights) {
    if (solved) {
      return;
    }
    if (now == target) {
      answer = current_value;
      solved = true;
      return;
    }
    for (std::string &neighbor : neighbors[now]) {
      if (visited.find(neighbor) == visited.end()) {
        visited.insert(neighbor);
        CalcEquation(neighbor, target, current_value * weights[now][neighbor], answer, solved, visited, neighbors, weights);
        visited.erase(neighbor);
      }
    }
  }

  std::vector<double> calcEquation(std::vector<std::pair<std::string, std::string> > equations, std::vector<double> &values, std::vector<std::pair<std::string, std::string> > queries) {
    std::set<std::string> variables;
    std::map<std::string, std::vector<std::string> > neighbors;
    std::map<std::string, std::map<std::string, double> > weights;
    const size_t N = equations.size();
    for (size_t i = 0; i < N; ++i) {
      variables.insert(equations[i].first);
      variables.insert(equations[i].second);
      neighbors[equations[i].first].push_back(equations[i].second);
      weights[equations[i].first][equations[i].second] = values[i];
      if (values[i]) {
        neighbors[equations[i].second].push_back(equations[i].first);
        weights[equations[i].second][equations[i].first] = 1.0 / values[i];
      }
    }
    std::vector<double> answer;
    for (const auto &query : queries) {
      std::set<std::string> visited{query.first};
      bool solved = false;
      double value = -1;
      if (variables.find(query.first) != variables.end()) {
        CalcEquation(query.first, query.second, 1, value, solved, visited, neighbors, weights);
      }
      answer.push_back(value);
    }
    return answer;
  }

};
