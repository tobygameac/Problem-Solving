class Solution {
 
 public:
  
  int maxProfit(std::vector<int> &prices) {
    int lowest = 2e9;
    int answer = 0;
    for (int price : prices) {
      if (price < lowest) {
        lowest = price;
      } else {
        int earned = price - lowest;
        answer = (earned > answer) ? earned : answer;
      }
    }
    return answer;
  }

};
