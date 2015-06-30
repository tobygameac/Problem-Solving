class Solution {
public:
    int reverse(int x) {
      bool minus = x < 0;
      x = x < 0 ? -x : x;
      long long revX = 0;
      while (x) {
        revX = revX * 10 + (x % 10);
        x /= 10;
      }
      revX = revX * (minus ? -1 : 1);
      if (revX > (((long long)1 << 31) - 1)) {
        return 0;
      }
      if (revX < -((long long)1 << 31)) {
        return 0;
      }
      return revX;
    }
};

int main() {
  return 0;
}
