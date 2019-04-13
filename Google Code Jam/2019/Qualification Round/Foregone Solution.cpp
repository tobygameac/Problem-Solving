#include <cstdio>
#include <cstring>

void SplitNumber(char *N, char *M) {
  for (int i = 0; N[i]; ++i) {
    int d = N[i] - '0';
    if (d == 7) {
      N[i] = '2';
      M[i] = '5';
    } else if (d == 8) {
      N[i] = '3';
      M[i] = '5';
    } else if (d == 9) {
      N[i] = '3';
      M[i] = '6';
    } else {
      N[i] = '0' + (d / 2);
      M[i] = '0' + (d / 2) + (d & 1);
    }
  }
}

void RemovePrefixZero(char *N) {
  int i;
  for (i = 0; N[i]; ++i) {
    if ((N[i] != '0') || !N[i + 1]) {
      break;
    }
  }
  strcpy(N, N + i);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    char N[111], M[111];
    scanf("%s", N);
    for (int i = 0; N[i]; ++i) {
      M[i] = '0';
      M[i + 1] = 0;
    }
    SplitNumber(N, M);
    RemovePrefixZero(N);
    RemovePrefixZero(M);
    printf("Case #%d: %s %s\n", t, N, M);
  }
  return 0;
}
