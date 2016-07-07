class Solution {
 
 public:
  
  bool canMeasureWater(int x, int y, int z) {
    if (z && (x + y) < z) {
      return false;
    }
    if (y) {
      while ((x %= y) && (y %= x));
    }
    int gcd = x + y;
    return !z || (gcd && (z >= gcd) &&!(z % gcd));
  }


};
