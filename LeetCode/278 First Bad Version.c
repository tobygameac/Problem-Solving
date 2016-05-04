#include <stdio.h>
#include <stdbool.h>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
  int l = 1;
  int r = n;
  while (l < r) {
    int mid = ((size_t)l + r) / 2;
    if (isBadVersion(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}

int main() {
  return 0;
}
