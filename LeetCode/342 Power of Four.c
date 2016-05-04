#include <stdio.h>
#include <stdbool.h>

bool isPowerOfFour(int num) {
  const int MASK = 0x55555555;
  return (num > 0) && !(num & (num - 1)) && (num == (num & MASK));
}

int main() {
  return 0;
}
