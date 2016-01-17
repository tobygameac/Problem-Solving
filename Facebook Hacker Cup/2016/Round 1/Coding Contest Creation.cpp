#include <iostream>
#include <algorithm>

size_t scores[111111];

int main() {
  size_t T;
  std::cin >> T;
  for (size_t t = 1; t <= T; ++t) {
    size_t N;
    std::cin >> N;
    
    for (size_t i = 0; i < N; ++i) {
      std::cin >> scores[i];
    }

    size_t previous_score = 0;
    size_t current_count = 0;
    size_t add_count = 0;

    for (size_t i = 0; i < N; ++i) {
      if (!current_count) {
        previous_score = scores[i];
        current_count = 1;
        continue;
      }
      if (scores[i] <= previous_score) {
        add_count += 4 - current_count;
        current_count = 1;
        previous_score = scores[i];
      } else {
        if (scores[i] - previous_score <= 10) {
          previous_score = scores[i];
        } else {
          previous_score += 10;
          --i;
          ++add_count;
        }
        current_count = (current_count + 1) % 4;
      }
    }

    if (current_count) {
      add_count += 4 - current_count;
    }

    std::cout << "Case #" << t << ": " << add_count << "\n";
  }
  return 0;
}
