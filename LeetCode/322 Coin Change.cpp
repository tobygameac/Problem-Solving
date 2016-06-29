class Solution {

 public:

  int coinChange(std::vector<int> &coins, int amount) {
    std::vector<int> need(amount + 1, amount + 1);
    need[0] = 0;
    for (int coin : coins) {
      for (int price = coin; price <= amount; ++price) {
        need[price] = std::min(need[price], need[price - coin] + 1);
      }
    }
    return (need[amount] <= amount) ? need[amount] : -1;
  }

};
