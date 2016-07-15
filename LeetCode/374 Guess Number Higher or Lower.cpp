int guess(int num);

class Solution {
 
 public:
  
  int guessNumber(int n) {
    int l = 1, r = n;
    while (l <= r) {
      int mid = ((long long)l + r) / 2;
      int g = guess(mid);
      if (!g) {
        return mid;
      }
      if (g > 0) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return 0;
  }

};
