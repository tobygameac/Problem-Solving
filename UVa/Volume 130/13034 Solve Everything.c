#include <stdio.h>

int main() {
  int total_set;
  while (scanf("%d", &total_set) == 1) {
    int current_set = 1;
    while (current_set <= total_set) {
      int ok = 1;
      int problem_count = 13;
      while (problem_count--) {
        int solved_count;
        scanf("%d", &solved_count);
        ok *= solved_count ? 1 : 0;
      }
      printf("Set #%d: %s\n", current_set++, ok ? "Yes" : "No");
    }
  }
  return 0;
}
