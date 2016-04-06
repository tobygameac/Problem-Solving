#include <stdio.h>

int main() {
  int type, guess;
  while (scanf("%d", &type) == 1) {
    int i, correct = 0;
    for (i = 0; i < 5; ++i) {
      int guess;
      scanf("%d", &guess);
      correct += guess == type;
    }
    printf("%d\n", correct);
  }
  return 0;
}
