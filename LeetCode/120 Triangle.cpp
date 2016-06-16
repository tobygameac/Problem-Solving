class Solution {
 
 public:
  
  int minimumTotal(std::vector<std::vector<int>> &triangle) {
    const size_t R = triangle.size();
    if (!R) {
      return 0;
    }
    std::vector<int> solution(R + 1, 2e9);
    solution[1] = triangle[0][0];
    for (size_t r = 1; r < R; ++r) {
      for (int c = r; c >= 0; --c) {
        solution[c + 1] = std::min(solution[c + 1], solution[c]) + triangle[r][c];
      }
    }
    int answer = 2e9;
    for (size_t c = 1; c <= R; ++c) {
      answer = std::min(answer, solution[c]);
    }
    return answer;
  }

};
