class Solution {
 public:
  bool isUgly(int num) {
    while (num > 1) {
      if (!(num % 2)) {
        num /= 2;
      } else if (!(num % 3)) {
        num /= 3;
      } else if (!(num % 5)) {
        num /= 5;
      } else {
        return false;
      }
    }
    return num == 1;
  }
};

int main() {
  return 0;
}
