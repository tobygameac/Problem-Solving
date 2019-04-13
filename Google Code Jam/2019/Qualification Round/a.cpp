#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <vector>

std::vector<int> prime_table;

void BuildPrimeTable() {
  const size_t MAX_PRIME = 10001;
  bool not_prime[MAX_PRIME] = {};
  not_prime[0] = not_prime[1] = true;
  for (int i = 2; i < MAX_PRIME; ++i) {
    if (!not_prime[i]) {
      prime_table.push_back(i);
      for (int j = i + i; j < MAX_PRIME; j += i) {
        not_prime[j] = true;
      }
    }
  }
}

void DecodeAndInsert(int n, std::set<int> &prime_set) {
  for (int prime : prime_table) {
    if (!(n % prime)) {
      prime_set.insert(prime);
      prime_set.insert(n / prime);
    }
  }
}

int main() {
  BuildPrimeTable();
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int N, L, code[111];
    scanf("%d%d", &N, &L);

    std::set<int> prime_set;
    for (int l = 0; l < L; ++l) {
      scanf("%d", &code[l]);
      DecodeAndInsert(code[l], prime_set);
    }

    std::map<int, int> prime_index;
    int current_index = 0;
    for (int prime : prime_set) {
      printf("%c : %d\r\n", current_index + 'A', prime);
      prime_index[prime] = current_index++;
    }

    std::string s;
    int previous_a, previous_b;
    for (int l = 0; l < L; ++l) {
      int a, b;
      for (int prime : prime_set) {
        if (!(code[l] % prime)) {
          a = prime, b = code[l] / prime;
          break;
        }
      }

      if (l) {
        bool add_b = ((a == previous_a) || (b == previous_a));
        s.insert(s.end(), prime_index[add_b ? previous_b : previous_a] + 'A');
        if ((l + 1) == L) { // the last
          s.insert(s.end(), prime_index[add_b ? previous_a : previous_b] + 'A');
          add_b = ((a == previous_a) || (a == previous_b));
          s.insert(s.end(), prime_index[(add_b ? b : a)] + 'A');
        }
      }

      previous_a = a;
      previous_b = b;
    }
    printf("Case #%d: %s\n", t, s.c_str());
  }
  return 0;
}
