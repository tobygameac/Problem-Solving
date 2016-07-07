class Solution {
 
 public:
  
  int Pow(int a, int b, int mod) {
    if (!b) {
      return 1;
    }
    return (((int)std::pow(Pow(a, b / 2, mod), 2) % mod) * (((b & 1) ? a : 1) % mod)) % mod;
  }

  int superPow(int a, std::vector<int> &b) {
    int answer = 1;
    int tenth_power = a;
    for (int i = b.size() - 1; i >= 0; --i) {
      answer = (answer * Pow(tenth_power, b[i], 1337)) % 1337;
      tenth_power = Pow(tenth_power, 10, 1337);
    }
    return answer;
  }

};
