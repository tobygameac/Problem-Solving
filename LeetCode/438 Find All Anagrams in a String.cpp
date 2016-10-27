class Solution {

 public:

  std::vector<int> findAnagrams(std::string s, std::string p) {
    const size_t N = s.length();
    const size_t M = p.length();
    
    size_t target_count[26] = {};
    for (char c : p) {
      ++target_count[c - 'a'];
    }

    size_t count[26] = {};
    for (size_t i = 0; (i + 1) < M && i < N; ++i) {
      ++count[s[i] - 'a'];
    }
    
    std::vector<int> answer;
    for (size_t i = 0; (i + M - 1) < N; ++i) {
      ++count[s[i + M - 1] - 'a'];
      bool solved = true;
      for (size_t c = 0; solved && (c < 26); ++c) {
        solved = target_count[c] == count[c];
      }
      if (solved) {
        answer.push_back(i);
      }
      --count[s[i] - 'a'];
    }

    return answer;
  }

};
