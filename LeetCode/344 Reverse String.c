#include <stdio.h>

char *reverseString(char *s) {
  char *tail = s;
  while (*tail) {
    ++tail;
  }
  --tail;
  char *head = s;
  while (head < tail) {
    char temp = *head;
    *head++ = *tail;
    *tail-- = temp;
  }
  return s;
}

int main() {
  return 0;
}
