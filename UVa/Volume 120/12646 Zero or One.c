#include <stdio.h>

int main() {
  int num[3];
  char sign[4] = "ABC*";
  while (scanf("%d%d%d", &num[0], &num[1], &num[2]) == 3) {
    int result = 3;
    int i;
    int sum = num[0] + num[1] + num[2];
    if (sum == 1) {
      for (i = 0; i < 3; ++i) {
        result = num[i] ? i : result;
      }
    } else if (sum == 2) {
      for (i = 0; i < 3; ++i) {
        result = !num[i] ? i : result;
      }
    }
    printf("%c\n", sign[result]);
  }
  return 0;
}
