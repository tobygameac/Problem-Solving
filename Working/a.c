#include <stdio.h>

int main() {
  int a, b;
  while (scanf("%d%d", &a, &b) && (a || b)) {
    int value, carry = 0, count = 0;
    while (a || b || carry) {
      count += carry;
      value = (a % 10) + (b % 10) + carry;
      carry = value / 10;
      value = value % 10;
      a /= 10;
      b /= 10;
    }
    if (count) {
      printf("%d carry operation%s.\n", count, count > 1 ? "s" : "");
    } else {
      puts("No carry operation.");
    }
  }
  return 0;
}
