class Solution {

 public:

  size_t SqrDistance(const std::pair<int, int> &p, const std::pair<int, int> &q) {
    return (p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second);
  }

  size_t Factorial(size_t n) {
    size_t sum = 1;
    for (size_t i = 1; i <= n; ++i) {
      sum *= i;
    }
    return sum;
  }

  int numberOfBoomerangs(std::vector<std::pair<int, int> > &points) {
    const size_t N = points.size();
    size_t count = 0;
    std::vector<std::vector<size_t> > distance(N, std::vector<size_t>(N, 0));
    
    for (size_t i = 0; i < N; ++i) {
      for (size_t j = i + 1; j < N; ++j) {
        distance[i][j] = distance[j][i] = SqrDistance(points[i], points[j]);
      }
    }

    for (size_t i = 0; i < N; ++i) {
      std::unordered_map<size_t, size_t> distance_count;
      for (size_t j = 0; j < N; ++j) {
        ++distance_count[distance[i][j]];
      }
      for (auto &p : distance_count) {
        count += p.second * (p.second - 1);
      }
    }
    return count;
  }

};
