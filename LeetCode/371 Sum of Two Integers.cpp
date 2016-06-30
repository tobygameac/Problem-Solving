class Solution {
 
 public:
   
  int getSum(int a, int b) {
    int c = a & b;
    return c ? getSum((a | b) ^ c, c << 1) : (a | b);
  }

};
